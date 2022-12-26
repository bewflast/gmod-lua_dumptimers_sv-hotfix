#include <GarrysMod/Lua/Interface.h>
#include <IFacesBook.hpp>


class ConCommandBase;

class IAppSystem
{
public:
	virtual	void	empty1() = 0;
	virtual	void	empty2() = 0;
	virtual	void	empty3() = 0;
	virtual	void	empty4() = 0;
	virtual	void	empty5() = 0;
};

class ICvar : public IAppSystem
{
    public:
        virtual	void			empty6();
        virtual	void			empty7();
        virtual void            UnregisterConCommand( ConCommandBase *pCommandBase ) = 0;
        virtual	void			empty8();
        virtual	void			empty9();
        virtual ConCommandBase *FindCommandBase( const char *name ) = 0;

};

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