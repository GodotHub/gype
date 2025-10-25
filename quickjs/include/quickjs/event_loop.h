#ifndef __EVENT_LOOP_H__
#define __EVENT_LOOP_H__

typedef struct JSContext JSContext;
typedef struct JSRuntime JSRuntime;

#ifdef __cplusplus
extern "C" {
#endif

void *event_loop(void *arg);
void execute_events();
void create_event_loop(JSRuntime *rt);

#ifdef __cplusplus
}
#endif
#endif // __EVENT_LOOP_H__