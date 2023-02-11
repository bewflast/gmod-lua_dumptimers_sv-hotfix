#ifndef     ICVAR_HPP

# define    ICVAR_HPP
# define    GET_VIRTUAL_METHOD_BY_INDEX(index) (*(*reinterpret_cast< uintptr_t** >(this) + index))

# include   <cstdint>

# ifdef __linux__
#  define __thiscall
# endif

#  define ICVAR_INTERFACE_VERSION       ((sizeof(void*) == 8) ? "VEngineCvar007"    : "VEngineCvar004"  )
#  define FIND_COMMAND_BASE_INDEX	    ((sizeof(void*) == 8) ? 14 		            : 10		        )
#  define UNREGISTER_CON_COMMAND_INDEX 	((sizeof(void*) == 8) ? 11 		            : 7		            )

class ConCommandBase;

class ICvar
{

    using FindCommandBaseFn_ptr         = ConCommandBase*   ( __thiscall* )( void* , const char*      );
    using UnregisterConCommandFn_ptr    = void              ( __thiscall* )( void* , ConCommandBase*  );


public:
    void            UnregisterConCommand    ( ConCommandBase *pCommandBase );
    ConCommandBase* FindCommandBase         ( const char *name );

};

#endif
