/*H********************************************************************************
* Ime datoteke: serverLinux.cpp
*
* Opis:
*		Enostaven strežnik, ki zmore sprejeti le enega klienta naenkrat.
*		Stre�nik sprejme klientove podatke in jih v nespremenjeni obliki po�lje
*		nazaj klientu - odmev.
*
*H*/

//Vklju�imo ustrezna zaglavja
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<pthread.h>
/*
Definiramo vrata (port) na katerem bo stre�nik poslu�al
in velikost medponilnika za sprejemanje in po�iljanje podatkov
*/
#define PORT 1053
#define BUFFER_SIZE 256
#define NTHREADS 64
struct arguments{
	int ID;
	int running;
	int clientsock;
};
pthread_t arr_t[NTHREADS];
struct arguments arr_a[NTHREADS];

void *user_connect_t(void*arg){
	struct arguments *t_args;
	t_args = (struct arguments*)arg;
	int clientSock,iResult;
	char buff[BUFFER_SIZE];
	do{
		clientSock=t_args->clientsock;
        	//Sprejmi podatke
		iResult = recv(clientSock, buff, BUFFER_SIZE, 0);

		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);

			//Vrni prejete podatke po�iljatelju
			iResult = send(clientSock, buff, iResult, 0 );
			if (iResult == -1) {
				printf("send failed!\n");
				close(clientSock);
				break;
			}
			printf("Thread %d sent: %d bytes.\n", t_args->ID,iResult);
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else{
			printf("recv failed!\n");
			close(clientSock);
			break;
		}

	} while (iResult > 0);
        if(pthread_detach(arr_t[t_args->ID])< 0){
            printf("Error detaching thread");
        }
        arr_a[t_args->ID].running=0;
        return NULL;
}

int main(int argc, char **argv){

	//Spremenjlivka za preverjane izhodnega statusa funkcij
	int iResult;
	/*
	Ustvarimo nov vti�, ki bo poslu�al
	in sprejemal nove kliente preko TCP/IP protokola
	*/
	int listener=socket(AF_INET, SOCK_STREAM, 0);
	if (listener == -1) {
		printf("Error creating socket\n");
		return 1;
	}

	//Nastavimo vrata in mre�ni naslov vti�a zažene z začetka
	sockaddr_in  listenerConf;
	listenerConf.sin_port=htons(PORT);
	listenerConf.sin_family=AF_INET;
	listenerConf.sin_addr.s_addr=INADDR_ANY;

	//Vti� pove�emo z ustreznimi vrati, zažene z začetka
	iResult = bind( listener, (sockaddr *)&listenerConf, sizeof(listenerConf));
	if (iResult == -1) {
		printf("Bind failed\n");
		close(listener);
		return 1;
    }

	//Za�nemo poslu�ati, zažene z začetka
	if ( listen( listener, 5 ) == -1 ) {
		printf( "Listen failed\n");
		close(listener);
		return 1;
	}

	//Definiramo nov vti� in medpomnilik
	int clientSock;
	
	/*
	V zanki sprejemamo nove povezave
	in jih stre�emo (najve� eno naenkrat)
	*/
	while (1)
	{
		//Sprejmi povezavo in ustvari nov vti�, čaka uporabnika, tukaj bo naredil thread
		clientSock = accept(listener,NULL,NULL);
                if (clientSock == -1) {
			printf("Accept failed\n");
			close(listener);
			return 1;
		}
                for(int i=1; i<NTHREADS; i++){
                    if(arr_a[i].running==0){
                        arr_a[i].ID=i;
                        arr_a[i].running=1;
                        arr_a[i].clientsock=clientSock;
                        pthread_create(&arr_t[i],NULL,user_connect_t,&arr_a[i]);
                        break;
                    }
                    if(i==NTHREADS-1){
                        close(clientSock);
                        printf("Sorry all threads are in use, try in a bit");
                    }
                }
	}

	close(listener);

	return 0;
}