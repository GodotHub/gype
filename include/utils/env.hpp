#ifndef __ENV_H__
#define __ENV_H__

typedef struct JSContext JSContext;
typedef struct JSRuntime JSRuntime;

extern JSContext *js_context();
extern JSRuntime *js_runtime();

#endif // __ENV_H__