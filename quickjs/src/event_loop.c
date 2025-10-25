#include "quickjs/event_loop.h"
#include "quickjs/quickjs.h"
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static pthread_t event_thread;

void *event_loop(void *arg) {
	int err;
	JSContext *pctx;
	JSRuntime *rt = (JSRuntime *)arg;
	while (1) {
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);

		while ((err = JS_ExecutePendingJob(rt, &pctx)) > 0) {
		}

		pthread_mutex_unlock(&mutex);

		if (err < 0) {
			printf("Error executing pending job\n");
			break;
		}
	}
	return NULL;
}

// 通知事件循环有新任务
void execute_events() {
	pthread_cond_signal(&cond);
	// pthread_join(event_thread, NULL);
}

void create_event_loop(JSRuntime *rt) {
	pthread_create(&event_thread, NULL, event_loop, rt);
}
