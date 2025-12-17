char cStatus			[50] =  {NULL};
char sTIME				[20] = " ";
char sDATE				[20] = " ";
char sFPS               [20] = " ";
char User               [20] = "User:";
char str                [20] = " ";
char *comi[] = {"OFF","Coming Soon"};
char *Level[] = {"OFF","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30"
,"31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50",
"51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80"
,"81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100"};
char *cross	[] = {"OFF","Red","Green","Blue","Orange","Purple","Black","White"};
/*Group*/
int group1;
int group2;
int group3;
int group4;
int group5;
int PXRelated;
/*D3D*/
int		ChamsSel	  = 0;
int		Chams         = 0;
int		Chams2        = 0;
int NoFogg;
int FullBright;
int GlassWalls;
int Crosshaird3d;
int CQCProne;
/*Player*/
struct Player
{
	int NFD;
	int superjmp;
	int PlayerSpeed;
	int STAMINA;
	int CH_Speedroll;
	int NoSpawnWait;
	int CH_NoBounds;
	int FastAmmo;
	int FastMedic;
	int FastRepair;
	int FastFlag;
	int Antiafk;
	int ImDrunk;
	int WTW;
	int AutoAmmoMedic;


}cPlayer;
struct Weapon
{
	int PXHACK;
	int CH_SUPEREXPLOSION;
	int CH_STW;
	int CH_NORECOIL;
	int CH_SUPERNOSPREAD;
	int CH_NoSpread;
	int CH_QUICKPLANT;
	int CH_QuickDefuse;
	int CH_FastLockOn;
	int CH_Scope;
	int CH_NoDelay;
	int CH_NoReload;
	int CH_Unlimitedammo;
	int Defuseanywhere;
	int Plantanywhere;
	int CH_Bullets;
	int CH_FastNadeBlast;
	int CH_ControlNade;
	int CH_BoneShot;
}cWeapon;
struct tBot
{
	int CH_Folder;
	int CH_AutoEnter;
	int CH_AutoShot;
	int CH_AutoStart;
	int CH_AutoReady;
	int CH_AutoPlant;
	int CH_AutoDefuse;
	int CH_AutoBomb;
	int CH_AutoNipper;
	int CH_AutoSuicide;
}cBot;
struct OPK
{
	int AntiOpk;
	int CH_OPK;
	int CH_SVP;
}cOPK;
struct Menu
{
	int ExitWr;
	int PanicKey;
	int infobox;

}cMenu;
struct Server
{

	int CH_5Slot;
	int CH_6Slot;
	int CH_7Slot;
	int CH_Invisible;
	int CH_8Slot;
	int AllSlots;
	int Premium;
	int Dinar;
	int Level;
	int CH_GM;
}cServer;




/*Char*/
char	*xChams[]	   = { "OFF","Red","Green","Blue","Orange","Purple","Pink","Black","Cyan","White"};
char	*grp[]     = { "[+]","[-]" };
char	*offon[]   = { "OFF","ON" };
char    *prem[]    = { "OFF","Bronze","Silver","Gold","Platinum"};
char    *speed[]   = { "OFF","10","20","30","40","50"};
char    *warn[]    = { "OFF","Message","Crash!"};