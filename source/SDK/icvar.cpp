#include "SDK/icvar.hpp"

ConCommandBase* ICvar::FindCommandBase( const char *name )
{
    ICvar::FindCommandBaseFn_ptr FCB_p = reinterpret_cast< ICvar::FindCommandBaseFn_ptr >(GET_VIRTUAL_METHOD_BY_INDEX(10));

    return ( FCB_p(this, name) );
};

void            ICvar::UnregisterConCommand( ConCommandBase *pCommandBase )
{
    ICvar::UnregisterConCommandFn_ptr UCC = reinterpret_cast< ICvar::UnregisterConCommandFn_ptr >(GET_VIRTUAL_METHOD_BY_INDEX(7));
    
    UCC(this, pCommandBase);
};