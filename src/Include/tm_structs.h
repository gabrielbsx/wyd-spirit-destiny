/* 2497 */
struct MSG_STANDARD
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
};


struct STRUCT_DAM
{
	unsigned short TargetID;
	int Damage;
};

struct STRUCT_AFFECT
{
	unsigned char Type;
	unsigned char Level;
	short Value;
	int Time;
};

struct STRUCT_STATICEFFECT
{
	short sEffect;
	short sValue;
};

/* 2225 */
struct STRUCT_BONUSEFFECT
{
	unsigned char cEffect;
	unsigned char cValue;
};

/* 2226 */
struct STRUCT_ITEM
{
	short sIndex;
	STRUCT_BONUSEFFECT stEffect[3];
};

struct STRUCT_SCORE
{
	short Level;
	int Ac;
	int Damage;
	unsigned char Reserved;
	unsigned char AttackRun;
	int MaxHp;
	int MaxMp;
	int Hp;
	int Mp;
	short Str;
	short Int;
	short Dex;
	short Con;
	unsigned short Special[4];
};


struct STRUCT_SELCHAR
{
	unsigned short HomeTownX[4];
	unsigned short HomeTownY[4];
	char MobName[4][16];
	STRUCT_SCORE Score[4];
	STRUCT_ITEM Equip[4][16];
	unsigned short Guild[4];
	int Coin[4];
	long long Exp[4];
};


struct STRUCT_ITEMLIST
{
	char Name[64];
	short nIndexMesh;
	short nIndexTexture;
	short nIndexVisualEffect;
	short nReqLvl;
	short nReqStr;
	short nReqInt;
	short nReqDex;
	short nReqCon;
	STRUCT_STATICEFFECT stEffect[12];
	int nPrice;
	short nUnique;
	short nPos;
	short nExtra;
	short nGrade;
};


struct  MSG_CHARPASSWORD
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char ItemPassWord[16];
	char State;
};

/* 2506 */
struct MSG_CharacterLogin
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	int Force;
	char SecretCode[16];
};

/* 2507 */
struct MSG_NewCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	char MobName[16];
	int Class;
};

/* 2508 */
struct MSG_ReqTransper
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Result;
	int Slot;
	char OldName[16];
	char NewName[16];
};

/* 2509 */
struct MSG_DeleteCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	char MobName[16];
	char Password[16];
};

/* 2510 */
struct MSG_STANDARDPARM2
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Parm1;
	int Parm2;
};

/* 2511 */
struct MSG_CNFNewCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_SELCHAR SelChar;
};

/* 2512 */
struct STRUCT_EXT1
{
	int Data[8];
	STRUCT_AFFECT Affect[32];
};

/* 2513 */
struct STRUCT_SUBCLASS
{
	unsigned int LearnedSkill[2];
	STRUCT_ITEM Equip;
	STRUCT_SCORE CurrentScore;
	long long Exp;
	char ShortSkill[20];
	short ScoreBonus;
	short SkillBonus;
};

/* 2514 */
struct STRUCT_EXT2
{
	char Quest[12];
	unsigned int LastConnectTime;
	STRUCT_SUBCLASS SubClass[2];
	char ItemPassWord[16];
	unsigned int ItemPos;
	int SendLevItem;
	short AdminGuildItem;
	char Dummy[126];
};

struct STRUCT_MOB
{
	char MobName[16];
	char Clan;
	unsigned char Merchant;
	unsigned short Guild;
	unsigned char Class;
	unsigned char Rsv;
	unsigned short Quest;
	int Coin;
	long long Exp;
	unsigned short HomeTownX;
	unsigned short HomeTownY;
	STRUCT_SCORE BaseScore;
	STRUCT_SCORE CurrentScore;
	STRUCT_ITEM Equip[16];
	STRUCT_ITEM Carry[64];
	unsigned int LearnedSkill[2];
	short ScoreBonus;
	short SpecialBonus;
	short SkillBonus;
	unsigned char Critical;
	unsigned char SaveMana;
	char ShortSkill[4];
	unsigned char GuildLevel;
	unsigned char Magic;
	unsigned char RegenHP;
	unsigned char RegenMP;
	unsigned char Resist[4];
	char dummy[212];
	unsigned short CurrentKill;
	unsigned short TotalKill;
};


/* 2515 */
struct MSG_CNFCharacterLogin
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short PosX;
	short PosY;
	STRUCT_MOB MOB;
	unsigned short Slot;
	unsigned short ClientID;
	unsigned short Weather;
	char ShortSkill[16];
	STRUCT_EXT1 Ext1;
	STRUCT_EXT2 Ext2;
};

/* 2516 */
struct MSG_INITGULDNAME
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Parm;
	char GuildName[12];
};


/* 2601 */
struct MSG_REQGAMBLE
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned char GambleID;
	unsigned int BetCoin;
};

/* 2602 */
struct MSG_STANDARDPARM3
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Parm1;
	int Parm2;
	int Parm3;
};

/* 2603 */
struct PARTY
{
	char Class;
	char PartyIndex;
	short Level;
	short MaxHp;
	short Hp;
	unsigned short ID;
	char Name[16];
};

/* 2604 */
struct MSG_REQParty
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	PARTY Leader;
	int TargetID;
};

/* 2605 */
struct  MSG_ApplyBonus
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short BonusType;
	short Detail;
	unsigned short TargetID;
};

/* 2606 */
struct  MSG_CNFParty2
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short LeaderID;
	char LeaderName[16];
};


struct  MSG_REQShopList
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short TargetID;
};

/* 2613 */
struct  MSG_DropItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int SourType;
	int SourPos;
	int Rotate;
	unsigned short GridX;
	unsigned short GridY;
	unsigned short ItemID;
};

/* 2614 */
struct MSG_ReqBuy
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Pos;
	unsigned short TargetID;
	int Price;
	int Tax;
	STRUCT_ITEM item;
};

/* 2615 */
struct MSG_CreateItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short GridX;
	unsigned short GridY;
	unsigned short ItemID;
	STRUCT_ITEM Item;
	unsigned char Rotate;
	unsigned char State;
	char Height;
	unsigned char Create;
	unsigned short Owner;
};

/* 2616 */
struct MSG_UpdateItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int ItemID;
	short State;
	char Height;
	char dummy;
};

struct  MSG_UseItem2
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int SourType;
	int SourPos;
	int DestType;
	int DestPos;
	unsigned short GridX;
	unsigned short GridY;
	unsigned short ItemID;
	unsigned char Parm[16];
};

/* 2620 */
struct MSG_HellBuy
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short TargetID;
	short TargetCarryPos;
	short MyCarryPos;
	int Coin;
};

/* 2621 */
struct  MSG_Sell
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short TargetID;
	short MyType;
	short MyPos;
};

/* 2622 */
struct MSG_LongMessagePanel
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short Parm1;
	short Parm2;
	char Line[4][128];
};

/* 2623 */
struct MSG_ReqSummon
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Result;
	char Name[16];
};

/* 2624 */
struct  MSG_REQMobByID
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short MobID;
};

/* 2625 */
struct  MSG_CreateMobTrade
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short PosX;
	short PosY;
	unsigned short MobID;
	char MobName[16];
	unsigned short Equip[16];
	unsigned short Affect[32];
	unsigned short Guild;
	unsigned char GuildLevel;
	STRUCT_SCORE Score;
	unsigned short CreateType;
	unsigned char Equip2[16];
	char Nick[26];
	char Desc[24];
	char Server;
};


/* 2646 */
struct  MSG_CreateMob
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short PosX;
	short PosY;
	unsigned short MobID;
	char MobName[16];
	unsigned short Equip[16];
	unsigned short Affect[32];
	unsigned short Guild;
	unsigned char GuildLevel;
	STRUCT_SCORE Score;
	unsigned short CreateType;
	unsigned char Equip2[16];
	char Nick[26];
	char Server;
};

/* 2647 */
struct MSG_CNFDropItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int SourType;
	int SourPos;
	int Rotate;
	unsigned short GridX;
	unsigned short GridY;
};

/* 2648 */
struct MSG_CNFGetItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int DestType;
	int DestPos;
	STRUCT_ITEM Item;
};

/* 2649 */
struct  MSG_RemoveItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short ItemID;
};

/* 2650 */
struct  MSG_SwapItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned char SourType;
	unsigned char SourPos;
	unsigned char DestType;
	unsigned char DestPos;
	unsigned short TargetID;
};

/* 2651 */
struct MSG_ShopList
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int ShopType;
	STRUCT_ITEM List[27];
	int Tax;
};

/* 2652 */
struct MSG_RMBShopList
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int ShopType;
	STRUCT_ITEM List[39];
	int Tax;
};

/* 2653 */
struct MSG_Buy
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short TargetID;
	short TargetCarryPos;
	short MyCarryPos;
	int Coin;
};

/* 2654 */
struct MSG_CNFMobKill
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int FakeExp;
	unsigned short KilledMob;
	unsigned short Killer;
	long long Exp;
};

/* 2655 */
struct  MSG_AddParty
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	PARTY Party;
};

/* 2656 */
struct  MSG_SetHpMode
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Hp;
	short Mode;
};

/* 2657 */
struct MSG_EnvEffect
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short x1;
	short y1;
	short x2;
	short y2;
	short Effect;
	short EffectParm;
};

/* 2658 */
struct MSG_RESULTGAMBLE
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char cResult[5];
	char cResultPos[9];
	int iPresent;
	unsigned int Jackpot;
};

/* 2659 */
struct MSG_RandomQuiz
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Question[128];
	char Answer[4][32];
};

/* 2660 */
struct MSG_AutoKick
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int parm;
	char route[128];
};

struct STRUCT_REPURCHASEITEM
{
	int Order;
	STRUCT_ITEM stItem;
	int Price;
};

/* 2661 */
struct MSG_RepurchaseItems
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int target;
	STRUCT_REPURCHASEITEM Repurcharse[10];
};


/* 2663 */
struct STRUCT_INITITEM
{
	short PosX;
	short PosY;
	short sIndex;
	short Rotate;
};


/* 2795 */
struct MSG_CNFMessageBoxOk
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int CallBack;
	int Param;
};

/* 3621 */
struct MSG_MessageBoxYesNo
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Button1[16];
	char Button2[16];
	int CallBackYes;
	int CallBackNo;
	int Param;
	char String[128];
};

/* 3758 */
struct  MSG_SENDTID
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Account[16];
	long long Token;
	int Server;
};


/* 4003 */
struct  MSG_CNFParty
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short LeaderID;
};

/* 4195 */
struct MSG_LogMessageShort
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Message[128];
};


/* 4467 */
struct MSG_GoThrough
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	short PosX[4];
	short PosY[4];
};

/* 4538 */
struct MSG_MessageDBRecord
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char String[512];
};

/* 4969 */
struct MSG_GuildZoneReport
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Guild[5];
};


/* 5035 */
struct MSG_DBSaveMobAndQuit
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	STRUCT_MOB MOB;
	STRUCT_ITEM Cargo[128];
	int Coin;
	char ShortSkill[16];
	char AccountName[16];
	STRUCT_EXT1 Ext1;
	STRUCT_EXT2 Ext2;
};

struct STRUCT_ACCOUNT
{
	char AccountName[16];
	char AccountPass[16];
	char RealName[24];
	unsigned int SSN1;
	unsigned int SSN2;
	char Temp[102];
	STRUCT_AFFECT Affect[2];
	unsigned int AccountIndex;
	unsigned int AccountLastConnectTime;
	char ItemPassWord[16];
	unsigned short GameServer;
	unsigned short Rsv;
};


/* 5357 */
struct MSG_NewAccount
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_ACCOUNT ACCOUNT;
	int Version;
};

struct STRUCT_GUILDLIST
{
	int GuildIndex;
	char GuildName[4][12];
	unsigned char GCount;
	char Citizen;
	char Mandle;
	unsigned int Fame;
};

/* 5358 */
struct MSG_InitGuildlist
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_GUILDLIST gList;
};

/* 5962 */
struct  MSG_UNCapsuleCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short CapsuleIndex;
	char Account[16];
	char NewMobname[16];
};

/* 6144 */
struct MSG_DBSaveMob
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	STRUCT_MOB MOB;
	STRUCT_ITEM Cargo[128];
	int Coin;
	char ShortSkill[16];
	char AccountName[16];
	int Export;
	STRUCT_EXT1 Ext1;
	STRUCT_EXT2 Ext2;
};

/* 6348 */
struct MSG_CNFRemoveServerLogin
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_SELCHAR SelChar;
	char AccountName[16];
	STRUCT_ITEM Cargo[128];
	int Coin;
	char SecretCode[16];
	int SSN1;
	int SSN2;
	short PosX;
	short PosY;
	STRUCT_MOB MOB;
	unsigned short Slot;
	unsigned short ClientID;
	unsigned short Weather;
	char ShortSkill[16];
	STRUCT_EXT1 Ext1;
	STRUCT_EXT2 Ext2;
};

/* 6443 */
struct MSG_DBCNFAccountLoginMal
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_SELCHAR SelChar;
	STRUCT_ITEM Cargo[128];
	int Coin;
	char AccountName[16];
	char SecretCode[16];
	int SSN1;
	int SSN2;
	char TID[52];
};

/* 6605 */
struct MSG_NPCreateCharacter_Reply
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	char Account[16];
	int Result;
	char MobName[16];
};

/* 6608 */
struct MSG_LogMessageLong
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Message[384];
};

/* 6660 */
struct MSG_MessageDBImple
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Level;
	char String[128];
};


/* 6667 */
struct MSG_NPEnable
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char AccountName[16];
};

/* 6782 */
struct MSG_Synchronization
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	long long _now;
};

/* 6786 */
struct MSG_NPIDPASS
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Account[16];
	int Encode1;
	char Pass[16];
	int Encode2;
};

/* 6851 */
struct  MSG_CreateGuild
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int GuildIndex;
	char GuildName[12];
	char Clan;
};

/* 6853 */
struct MSG_DBA
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Contents[384];
	char From[32];
	char To[32];
	char ServerIP[32];
};

/* 6931 */
struct MSG_DBSavingQuit
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char AccountName[16];
	int Mode;
};

/* 6944 */
struct MSG_MessageBoxOk
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char String[128];
	int CallBack;
	int Param;
};

/* 6968 */
struct  MSG_TradeCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	unsigned short Slot;
	char Account[16];
	char Char[16];
};

/* 6996 */
struct MSG_GMMessage
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Account[16];
	char Char[16];
	char String[128];
};

/* 6998 */
struct MSG_MAXFAMEGUILD
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Rguild;
	int Bguild;
	int Rfame;
	int Bfame;
};

/* 7035 */
struct MSG_CNFDeleteCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_SELCHAR SelChar;
};

/* 7051 */
struct MSG_NPCreateCharacter
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Slot;
	char Account[16];
	STRUCT_MOB Mob;
	STRUCT_EXT1 Ext1;
	STRUCT_EXT2 Ext2;
};

/* 7064 */
struct MSG_NPReqAccount
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char Account[16];
	char Char[16];
};

/* 7080 */
struct MSG_GuildZoneInform
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Guild[10][5];
};


/* 7079 */
struct STRUCT_RUNEQUESTZONE
{
	int StartX;
	int StartY;
	int iLeader;
	int Type;
};


/* 7081 */
struct  MSG_AttackOne
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int FakeExp;
	int ReqMp;
	long long CurrentExp;
	short Rsv;
	unsigned short PosX;
	unsigned short PosY;
	unsigned short TargetX;
	unsigned short TargetY;
	unsigned short AttackerID;
	unsigned short Progress;
	unsigned char Motion;
	unsigned char FlagLocal;
	unsigned char DoubleCritical;
	unsigned char SkillParm;
	int CurrentMp;
	short SkillIndex;
	STRUCT_DAM Dam[1];
};

struct  MSG_Attack
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int FakeExp;
	int ReqMp;
	long long CurrentExp;
	short Rsv;
	unsigned short PosX;
	unsigned short PosY;
	unsigned short TargetX;
	unsigned short TargetY;
	unsigned short AttackerID;
	unsigned short Progress;
	unsigned char Motion;
	unsigned char FlagLocal;
	unsigned char DoubleCritical;
	unsigned char SkillParm;
	int CurrentMp;
	short SkillIndex;
	STRUCT_DAM Dam[13];
};

/* 7126 */
struct  MSG_CASHSERVER
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	char suss;
	char contents[64];
};


/* 7129 */
struct MSG_DBSendItem
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Result;
	char Account[16];
	STRUCT_ITEM Item;
};

/* 7140 */
struct MSG_USERCOMMAND
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int CommandNo;
	char String[128];
};

/* 7166 */
struct MSG_NPNotice
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int Parm1;
	int Parm2;
	char AccountName[16];
	char String[128];
};

/* 7175 */
struct  MSG_SubCreateGuild
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	int target;
	int GuildIndex;
	char Subindex;
	char GuildName[12];
};

struct STRUCT_ACCOUNTFILE
{
	STRUCT_ACCOUNT Account;
	STRUCT_MOB Char[4];
	STRUCT_ITEM Cargo[128];
	int Coin;
	char ShortSkill[4][16];
	STRUCT_EXT1 Ext1[4];
	STRUCT_EXT2 Ext2[4];
};

/* 7200 */
struct  MSG_NPAccountInfo
{
	unsigned short Size;
	unsigned char KeyWord;
	unsigned char CheckSum;
	unsigned short Type;
	unsigned short ID;
	unsigned int Tick;
	STRUCT_ACCOUNTFILE account;
	short Session;
	short State;
};

#define MAX_AFFECT 32
#define MAX_PARTY 12
struct CMob
{
	~CMob() {};
	STRUCT_MOB Mob; // 0 - 1024
	STRUCT_EXT1 EXT1; // 1024 - 
	STRUCT_EXT2 EXT2;
	STRUCT_AFFECT Affect[MAX_AFFECT];
	int Mode; // 1332 - 1335 = 1FDF1D4
	int Leader; // 1336 - 1339 = 1FDF1D8
	int Formation; // 1340 - 1343 = 1FDF1DC
	int RouteType; // 1344 - 1347 = 1FDF1E0
	int LastX; // 1348 - 1351 = 1FDF1E4
	int LastY; // 1352 - 1355 = 1FDF1E8
	unsigned int LastTime; // 1356 - 1359 = 1FDF1EC
	int LastSpeed; // 1360 - 1363 = 1FDF1F0
	int TargetX; // 1364 - 1367 = 1FDF1F4
	int TargetY; // 1368 - 1371 = 1FDF1F8
	int NextX; // 1372 - 1375 = 1FDF1FC
	int NextY; // 1376 - 1379 = 1FDF200
	int NextAction; // 1380 - 1383 = 1FDF204
	char Route[24]; // 1384 - 1407 = 1FDF208
	int WaitSec; // 1408 - 1411 = 1FDF220
	int UnknowByte_1412; // 1412 - 1415 = 1FDF224
	int SegmentHold; // 1416 - 1419 = 1FDF228
	int Segment; // 1420 - 1423 = 1FDF22C
	int SegmentX; // 1424 - 1427 = 1FDF230
	int SegmentY; // 1428 - 1431 = 1FDF234
	int SegmentListX[5]; // 1432 - 1451 = 1FDF238
	int SegmentListY[5]; // 1452 - 1471 = 1FDF24C
	int SegmentWait[5]; // 1472 - 1491 = 1FDF260
	int SegmentDirection; // 1492 - 1495 = 1FDF274
	int SegmentProgress; // 1496 - 1499 = 1FDF278
	int GenerateIndex; // 1500 - 1503 = 1FDF27C
	short CurrentTarget; // 1504 - 1505 = 1FDF280
	short EnemyList[4]; // 1506 - 1513 = 1FDF282
	short PartyList[MAX_PARTY]; // 1514 - 1537 = 1FDF28A
	short SummonList[MAX_PARTY];
	short UnknowByte_1538; // 1538 - 1539 = 1FDF2A2
	int WeaponDamage; // 1540 - 1543 = 1FDF2A4
	int Summoner; // 1544 - 1547  = 1FDF2A8
	int PotionCount; // 1548 - 1551 = 1FDF2AC
	int GuildDisable; // 1552 - 1555 = 1FDF2B0
	int DropBonus; // 1556 - 1559 = 1FDF2B4
	int ExpBonus; // 1560 - 1563 = 1FDF2B8
	int RangeBonus; // 1564 - 1567 = 1FDF2BC
	int ForceBonus; // 1568 - 1571 = 1FDF2C0
	int UnknowByte_1572; // 1572 - 1575 = 1FDF2C4
	int CurrentFace; // 1576 - 1579 = 1FDF2C8
	int QuestFlag; // 1580 - 1583 = 1FDF2CC
	int UnknowByte_1584; // 1584 - 1587 = 1FDF2D0
	int KhepraLive; // 1588 - 1591 = 1FDF2D4
	int BossType; // 1592 - 1595 = 1FDF2D8
	int UnknowByte_1596; // 1596 - 1599 = 1FDF2DC
	int UnknowByte_1600; // 1600 - 1603 = 1FDF2E0
	int ForceMobDamage; // 1604 - 1607 = 1FDF2E4
	unsigned int UnknowByte_1608; // 1608 - 1611 = 1FDF2E8
	int RegenHp; // 1612 - 1615 = 1FDF2EC
	int RegenMp; // 1616 - 1619 = 1FDF2F0
	int ForceDamage; // 1620 - 1623 = 1FDF2F4
	int ReflectDamage; // 1624 - 1627 = 1FDF2F8
	int	UnknowByte_1628; // 1628 - 1631 = 1FDF2FC
	int	UnknowByte_1632; // 1632 - 1635 = 1FDF300
	int	UnknowByte_1636; // 1636 - 1639 = 1FDF304
	int	UnknowByte_1640; // 1640 - 1643 = 1FDF308
	int UnknowByte_1644; // 1644 - 1647 = 1FDF30C
	unsigned int UnknowByte_1648; // 1648 - 1651 = 1FDF310
	int RuneQuestID; // 1652 - 1655 = 1FDF314
	int UnknowByte_1656; // 1656 - 1659 = 1FDF318
	char Tab[24]; // 1660 - 1683 = 1FDF31C
	char UnknowByte_1684; // 1684 = 1FDF334
	char UnknowByte_1685; // 1685 = 1FDF335
	short UnknowByte_1686; // 1686 - 1687 = 1FDF336
	int UnknowByte_1688; // 1688 - 1691 = 1FDF338
	int UnknowByte_1692; // 1692 - 1695 = 1FDF33C
	int UnknowByte_1696; // 1696 - 1699 = 1FDF340
	int UnknowByte_1700; // 1700 - 1703 = 1FDF344
	int UnknowByte_1704; // 1704 - 1707 = 1FDF348
	int Rsv; // 1708 - 1711 = 1FDF34C
	short BattleJewel; // 1712 - 1713 = 1FDF350
	short UnknowByte_1714; // 1714 - 1715 = 1FDF352
	int Accuracy; // 1716 - 1719 = 1FDF354
	int Parry;// 1720 - 1723 = 1FDF358
};