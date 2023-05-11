SET (bkds2010_lib
	bkds2010.cpp
	connectionHandler.cpp
	effectDispatcher.cpp
	commands/auto_rate.cpp
	commands/command.cpp
	commands/dsk.cpp
	commands/eff00_13.cpp
	commands/eff01_8a.cpp
	commands/eff01_9c.cpp
	commands/eff01_a1.cpp
	commands/eff25_82.cpp
	commands/eff2e_86.cpp
	commands/effect_chr.cpp
	commands/effect_keyer.cpp
	commands/effect_matte.cpp
	commands/enable.cpp
	commands/eventmem.cpp
	commands/gpiin.cpp
	commands/key.cpp
	commands/matteparams.cpp
	commands/mixparams.cpp
	commands/ping.cpp
	commands/select_xpt.cpp
	commands/setup_systm.cpp
	commands/sysinfo.cpp
	commands/tbar.cpp
	commands/trans.cpp
	commands/util.cpp
	commands/wipe.cpp
	commands/wipepos.cpp
	commands/wipeparams.cpp
	)

add_subdirectory(commands)
add_subdirectory(effects)

add_library(bkds2010 SHARED ${bkds2010_lib} ${bkds2010_lib_commands} ${bkds2010_lib_effects})

set_target_properties(
	bkds2010
	PROPERTIES
	SOVERSION ${BKDS_SWITCHER_VERSION_MAJOR}
	VERSION ${BKDS_SWITCHER_VERSION_MAJOR}.${BKDS_SWICTHER_VERSION_MINOR}.${BKDS_SWICTHER_VERSION_RELEASE}
)
