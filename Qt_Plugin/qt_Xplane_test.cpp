#include <XPlane/XPLM/XPLMDisplay.h>
#include <XPlane/XPLM/XPLMGraphics.h>
#include <XPlane/XPLM/XPLMDefs.h>
#include <XPlane/XPLM/XPLMUtilities.h>
#include <XPlane/XPLM/XPLMDataAccess.h>
#include <string.h>
#include <GL/gl.h>
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
// An opaque handle to the window we will create
/* We will store the information we got from our last key press globally
 * so the window can show the most recent key press. */

static XPLMKeyFlags	gFlags = 0;
static char			gVirtualKey = 0;
static char			gChar = 0;



static int MyKeySniffer(
        char                 inChar,
        XPLMKeyFlags         inFlags,
        char                 inVirtualKey,
        void *               inRefcon);
PLUGIN_API int XPluginStart(
        char *		outName,
        char *		outSig,
        char *		outDesc)
{
    strcpy(outName, "HelloWorld3Plugin");
    strcpy(outSig, "xpsdk.examples.helloworld3plugin");
    strcpy(outDesc, "A Hello World plug-in for the XPLM300 SDK.");

    /* Finally register our key sniffer. */
    XPLMRegisterKeySniffer(
            MyKeySniffer, 				/* Our callback. */
            1, 			/* Receive input before plugin windows. */
            0);					/* Refcon - not used. */

    return 1;


}

PLUGIN_API void	XPluginStop(void){

}

PLUGIN_API void XPluginDisable(void) { }
PLUGIN_API int  XPluginEnable(void)  { return 1; }
PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void * inParam) { }

/*
 * MyKeySniffer
 *
 * This routine receives keystrokes from the simulator as they are pressed.
 * A separate message is received for each key press and release as well as
 * keys being held down.
 *
 */
int MyKeySniffer(
        char                 inChar,
        XPLMKeyFlags         inFlags,
        char                 inVirtualKey,
        void *               inRefcon)
{
    /* First record the key data. */
    gVirtualKey = inVirtualKey;
    gFlags = inFlags;
    gChar = inChar;
    if ((int)gChar == 66 && (gFlags & xplm_ShiftFlag) && (gFlags & xplm_UpFlag)){
        XPLMSetDatai(XPLMFindDataRef("sim/time/sim_speed"), 0);
        int argc {1};
        char test_argv {'Q'};
        char *y = &test_argv;
        char **argv = &y;
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        a.exec();
    }
    return 1; // Should be 1, else other keys won't work
}


