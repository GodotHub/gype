#ifndef __EVENT_LOOP_H__
#define __EVENT_LOOP_H__

typedef struct JSContext JSContext;
typedef struct JSRuntime JSRuntime;

void *event_loop(void *arg);
void execute_events();
void create_event_loop(JSRuntime *rt);

#endif // __EVENT_LOOP_H__