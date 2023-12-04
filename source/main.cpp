#include <GarrysMod/Lua/Interface.h>
#include <source-engine-interfaces-book/IFacesBook.hpp>

#include "SDK/icvar.hpp"


GMOD_MODULE_OPEN()
{

    auto* icvarInterface = static_cast<ICvar*>(IFacesBook::getInterface("ICvar"));
    if (not icvarInterface) {
        LUA->ThrowError("Unable to get ICvar interface!");
	}

	auto* lua_dumptimers_sv   = icvarInterface->FindCommandBase("lua_dumptimers_sv");
    if (not lua_dumptimers_sv) {
        LUA->ThrowError("Unable to get lua_dumptimers_sv ConCMDBase!");
	}

    icvarInterface->UnregisterConCommand(lua_dumptimers_sv);
    
    return ( 0 );
}

GMOD_MODULE_CLOSE()
{
    return ( 0 );
}
