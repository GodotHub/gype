#ifndef __MODULE_LOADER_H__
#define __MODULE_LOADER_H__

typedef struct JSModuleDef JSModuleDef;
typedef struct JSContext JSContext;

JSModuleDef *module_loader(JSContext *ctx, const char *module_name, void *opaque);
#endif // __MODULE_LOADER_H__