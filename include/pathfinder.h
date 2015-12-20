#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
    /* Windows - set up dll import/export decorators. */
    #ifdef BUILDING_PATHFINDER_SHARED
        /* Building shared library. */
        #define PATHFINDER_EXTERN __declspec(dllexport)
    #else
        #ifdef USING_PATHFINDER_SHARED
            /* Using shared library. */
            #define PATHFINDER_EXTERN __declspec(dllimport)
        #else
            /* Building static library. */
            #define PATHFINDER_EXTERN /* nothing */
        #endif
    #endif

    #define PATHFINDER_CALLING_CONVENTION __cdecl
#else
    /* Building static library. */
    #define PATHFINDER_EXTERN /* nothing */
    #define PATHFINDER_CALLING_CONVENTION /* nothing */
#endif

typedef void* pathfinder;
    
PATHFINDER_EXTERN int pf_create(pathfinder* context);
PATHFINDER_EXTERN void pf_free(pathfinder* context);
PATHFINDER_EXTERN int pf_set(pathfinder* context, unsigned char* path, int path_length, void* value);
PATHFINDER_EXTERN int pf_find(pathfinder* context, unsigned char* path, int path_length, void* value);

#ifdef __cplusplus
}
#endif
