#ifndef     ICVAR_HPP

# define    ICVAR_HPP
# define    GET_VIRTUAL_METHOD_BY_INDEX(index) (*(*reinterpret_cast< uintptr_t** >(this) + index))

# include   <cstdint>

# ifdef __linux__

#  define __thiscall
#  define ICVAR_INTERFACE_VERSION "VEngineCvar004"
#  define FIND_COMMAND_BASE_INDEX 10
#  define UNREGISTER_CON_COMMAND_INDEX 7

# else

#  define ICVAR_INTERFACE_VERSION "VEngineCvar007"
#  define FIND_COMMAND_BASE_INDEX 14
#  define UNREGISTER_CON_COMMAND_INDEX 11

# endif

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