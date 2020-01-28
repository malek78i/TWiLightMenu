
#include "common/inifile.h"
#include "common/bootstrappaths.h"
#include "bootstrapsettings.h"
#include <string.h>

BootstrapSettings::BootstrapSettings()
{
    bstrap_debug = false;
	bstrap_logging = false;
	bstrap_romreadled = BootstrapSettings::ELEDNone;
	dmaromreadled = BootstrapSettings::ELEDSame;
	bstrap_loadingScreen = BootstrapSettings::ELoadingRegular;
	consoleModel = -1;
}

void BootstrapSettings::loadSettings()
{
    CIniFile bootstrapini(BOOTSTRAP_INI);

    // UI settings.
   	bstrap_debug = bootstrapini.GetInt("NDS-BOOTSTRAP", "DEBUG", bstrap_debug);
	bstrap_logging = bootstrapini.GetInt("NDS-BOOTSTRAP", "LOGGING", bstrap_logging);
	if (isDSiMode()) {
		bstrap_romreadled = bootstrapini.GetInt("NDS-BOOTSTRAP", "ROMREAD_LED", bstrap_romreadled);
		dmaromreadled = bootstrapini.GetInt("NDS-BOOTSTRAP", "DMA_ROMREAD_LED", dmaromreadled);
	}
	bstrap_loadingScreen = bootstrapini.GetInt( "NDS-BOOTSTRAP", "LOADING_SCREEN", bstrap_loadingScreen);
	consoleModel = bootstrapini.GetInt( "NDS-BOOTSTRAP", "CONSOLE_MODEL", consoleModel);
}

void BootstrapSettings::saveSettings()
{
     CIniFile bootstrapini(BOOTSTRAP_INI);

    // UI settings.
    bootstrapini.SetInt("NDS-BOOTSTRAP", "DEBUG", bstrap_debug);
	bootstrapini.SetInt("NDS-BOOTSTRAP", "LOGGING", bstrap_logging);
	if (isDSiMode()) {
		bootstrapini.SetInt("NDS-BOOTSTRAP", "ROMREAD_LED", bstrap_romreadled);
		bootstrapini.SetInt("NDS-BOOTSTRAP", "DMA_ROMREAD_LED", dmaromreadled);
	}
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "LOADING_SCREEN", bstrap_loadingScreen);
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "CONSOLE_MODEL", consoleModel);
    bootstrapini.SaveIniFile(BOOTSTRAP_INI);
}
