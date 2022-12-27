#ifndef     ICVAR_HPP

# define    ICVAR_HPP
# define    GET_VIRTUAL_METHOD_BY_INDEX(index) (*(*reinterpret_cast< uintptr_t** >(this) + index))

# include   <cstdint>

# ifdef __linux__
#  define __thiscall
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
