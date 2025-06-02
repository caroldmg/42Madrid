#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	for (int i; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	if ((pthread_create(&t1, NULL, &routine, NULL) != 0 )|| (pthread_create(&t2, NULL, &routine, NULL))) 
		return 1;
	if (pthread_join(t1, NULL) || pthread_join(t2, NULL))
		return 2;
	pthread_mutex_destroy(&mutex);
	printf("number of mails --> %d \n", mails);
	return (0);
}
