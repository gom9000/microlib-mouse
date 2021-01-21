IF EXIST gmouse.lib DEL gmouse.lib
IF EXIST gmouse.lst DEL gmouse.lst

LIB gmouse.lib /NOLOGO +m_init.obj,   gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_show.obj,   gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_getpos.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_setpos.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_getbpr.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_setvel.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_getsen.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_setsen.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_gettyp.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_getirq.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_getmov.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_butpre.obj, gmouse.lst, gmouse.lib
LIB gmouse.lib /NOLOGO +m_butrel.obj, gmouse.lst, gmouse.lib

IF EXIST gmouse.bak DEL gmouse.bak
