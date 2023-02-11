#include "SDK/icvar.hpp"

ConCommandBase* ICvar::FindCommandBase( const char *name )
{
    ICvar::FindCommandBaseFn_ptr FCB_p = reinterpret_cast< ICvar::FindCommandBaseFn_ptr >(GET_VIRTUAL_METHOD_BY_INDEX(FIND_COMMAND_BASE_INDEX));

    return ( FCB_p(this, name) );
};

void            ICvar::UnregisterConCommand( ConCommandBase *pCommandBase )
{
    ICvar::UnregisterConCommandFn_ptr UCC = reinterpret_cast< ICvar::UnregisterConCommandFn_ptr >(GET_VIRTUAL_METHOD_BY_INDEX(UNREGISTER_CON_COMMAND_INDEX));
    
    UCC(this, pCommandBase);
};