#ifndef     ICVAR_HPP

# define    ICVAR_HPP
# define    GET_VIRTUAL_METHOD_BY_INDEX(index) (*(*reinterpret_cast< uintptr_t** >(this) + index))

# include   <cstdint>

class ConCommandBase;

class ICvar
{
    #ifdef  _WIN32
        using FindCommandBaseFn_ptr         = ConCommandBase*   ( __thiscall* )( void* , const char*      );
        using UnregisterConCommandFn_ptr    = void              ( __thiscall* )( void* , ConCommandBase*  );
    #else
        using FindCommandBaseFn_ptr         = ConCommandBase*   (*)( void* , const char*      );
        using UnregisterConCommandFn_ptr    = void              (*)( void* , ConCommandBase*  );
    #endif

public:
    void            UnregisterConCommand    ( ConCommandBase *pCommandBase );
    ConCommandBase* FindCommandBase         ( const char *name );

};

#endif