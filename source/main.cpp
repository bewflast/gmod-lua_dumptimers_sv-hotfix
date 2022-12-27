#include <GarrysMod/Lua/Interface.h>
#include <IFacesBook.hpp>

#include "SDK/icvar.hpp"

#include <iostream>

GMOD_MODULE_OPEN()
{

    ICvar*          icvarInterface    (nullptr);
    IFacesBook      interfacesList;
    ConCommandBase* lua_dumptimers_sv (nullptr);

    icvarInterface = interfacesList.getInterface<ICvar>("VEngineCvar004");
    if (!icvarInterface)
        LUA->ThrowError("Unable to get ICvar interface!");

    lua_dumptimers_sv   = icvarInterface->FindCommandBase("lua_dumptimers_sv");
    if (!lua_dumptimers_sv)
        LUA->ThrowError("Unable to get lua_dumptimers_sv ConCMDBase!");

    icvarInterface->UnregisterConCommand(lua_dumptimers_sv);
    
    return ( 0 );
}

GMOD_MODULE_CLOSE()
{
    return ( 0 );
}