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
	
	STRUCT_ITEM(short id, BYTE ef1, BYTE efv1, BYTE ef2, BYTE efv2, BYTE ef3, BYTE efv3)
	{
		this->sIndex = id;
		this->stEffect[0].cEffect = ef1;
		this->stEffect[0].cValue = efv1;

		this->stEffect[1].cEffect = ef2;
		this->stEffect[1].cValue = efv2;


		this->stEffect[2].cEffect = ef3;
		this->stEffect[2].cValue = efv3;
	}
	STRUCT_ITEM()
	{
		this->sIndex = 0;
		this->stEffect[0].cEffect = 0;
		this->stEffect[0].cValue = 0;

		this->stEffect[1].cEffect = 0;
		this->stEffect[1].cValue = 0;


		this->stEffect[2].cEffect = 0;
		this->stEffect[2].cValue = 0;
	}
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
/* 182 */
struct __declspec(align(8)) CMob
{
	STRUCT_MOB Mob;
	unsigned __int8 byte_1025;
	unsigned __int8 byte_1026;
	unsigned __int8 byte_1027;
	unsigned __int8 byte_1028;
	unsigned __int8 byte_1029;
	unsigned __int8 byte_1030;
	unsigned __int8 byte_1031;
	unsigned __int8 byte_1032;
	unsigned __int8 byte_1033;
	unsigned __int8 byte_1034;
	unsigned __int8 byte_1035;
	unsigned __int8 byte_1036;
	unsigned __int8 byte_1037;
	unsigned __int8 byte_1038;
	unsigned __int8 byte_1039;
	unsigned __int8 byte_1040;
	unsigned __int8 byte_1041;
	unsigned __int8 byte_1042;
	unsigned __int8 byte_1043;
	unsigned __int8 byte_1044;
	unsigned __int8 byte_1045;
	unsigned __int8 byte_1046;
	unsigned __int8 byte_1047;
	unsigned __int8 byte_1048;
	unsigned __int8 byte_1049;
	unsigned __int8 byte_1050;
	unsigned __int8 byte_1051;
	unsigned __int8 byte_1052;
	unsigned __int8 byte_1053;
	unsigned __int8 byte_1054;
	unsigned __int8 byte_1055;
	unsigned __int8 byte_1056;
	unsigned __int8 byte_1057;
	unsigned __int8 byte_1058;
	unsigned __int8 byte_1059;
	unsigned __int8 byte_1060;
	unsigned __int8 byte_1061;
	unsigned __int8 byte_1062;
	unsigned __int8 byte_1063;
	unsigned __int8 byte_1064;
	unsigned __int8 byte_1065;
	unsigned __int8 byte_1066;
	unsigned __int8 byte_1067;
	unsigned __int8 byte_1068;
	unsigned __int8 byte_1069;
	unsigned __int8 byte_1070;
	unsigned __int8 byte_1071;
	unsigned __int8 byte_1072;
	unsigned __int8 byte_1073;
	unsigned __int8 byte_1074;
	unsigned __int8 byte_1075;
	unsigned __int8 byte_1076;
	unsigned __int8 byte_1077;
	unsigned __int8 byte_1078;
	unsigned __int8 byte_1079;
	unsigned __int8 byte_1080;
	unsigned __int8 byte_1081;
	unsigned __int8 byte_1082;
	unsigned __int8 byte_1083;
	unsigned __int8 byte_1084;
	unsigned __int8 byte_1085;
	unsigned __int8 byte_1086;
	unsigned __int8 byte_1087;
	unsigned __int8 byte_1088;
	unsigned __int8 byte_1089;
	unsigned __int8 byte_1090;
	unsigned __int8 byte_1091;
	unsigned __int8 byte_1092;
	unsigned __int8 byte_1093;
	unsigned __int8 byte_1094;
	unsigned __int8 byte_1095;
	unsigned __int8 byte_1096;
	unsigned __int8 byte_1097;
	unsigned __int8 byte_1098;
	unsigned __int8 byte_1099;
	unsigned __int8 byte_1100;
	unsigned __int8 byte_1101;
	unsigned __int8 byte_1102;
	unsigned __int8 byte_1103;
	unsigned __int8 byte_1104;
	unsigned __int8 byte_1105;
	unsigned __int8 byte_1106;
	unsigned __int8 byte_1107;
	unsigned __int8 byte_1108;
	unsigned __int8 byte_1109;
	unsigned __int8 byte_1110;
	unsigned __int8 byte_1111;
	unsigned __int8 byte_1112;
	unsigned __int8 byte_1113;
	unsigned __int8 byte_1114;
	unsigned __int8 byte_1115;
	unsigned __int8 byte_1116;
	unsigned __int8 byte_1117;
	unsigned __int8 byte_1118;
	unsigned __int8 byte_1119;
	unsigned __int8 byte_1120;
	unsigned __int8 byte_1121;
	unsigned __int8 byte_1122;
	unsigned __int8 byte_1123;
	unsigned __int8 byte_1124;
	unsigned __int8 byte_1125;
	unsigned __int8 byte_1126;
	unsigned __int8 byte_1127;
	unsigned __int8 byte_1128;
	unsigned __int8 byte_1129;
	unsigned __int8 byte_1130;
	unsigned __int8 byte_1131;
	unsigned __int8 byte_1132;
	unsigned __int8 byte_1133;
	unsigned __int8 byte_1134;
	unsigned __int8 byte_1135;
	unsigned __int8 byte_1136;
	unsigned __int8 byte_1137;
	unsigned __int8 byte_1138;
	unsigned __int8 byte_1139;
	unsigned __int8 byte_1140;
	unsigned __int8 byte_1141;
	unsigned __int8 byte_1142;
	unsigned __int8 byte_1143;
	unsigned __int8 byte_1144;
	unsigned __int8 byte_1145;
	unsigned __int8 byte_1146;
	unsigned __int8 byte_1147;
	unsigned __int8 byte_1148;
	unsigned __int8 byte_1149;
	unsigned __int8 byte_1150;
	unsigned __int8 byte_1151;
	unsigned __int8 byte_1152;
	unsigned __int8 byte_1153;
	unsigned __int8 byte_1154;
	unsigned __int8 byte_1155;
	unsigned __int8 byte_1156;
	unsigned __int8 byte_1157;
	unsigned __int8 byte_1158;
	unsigned __int8 byte_1159;
	unsigned __int8 byte_1160;
	unsigned __int8 byte_1161;
	unsigned __int8 byte_1162;
	unsigned __int8 byte_1163;
	unsigned __int8 byte_1164;
	unsigned __int8 byte_1165;
	unsigned __int8 byte_1166;
	unsigned __int8 byte_1167;
	unsigned __int8 byte_1168;
	unsigned __int8 byte_1169;
	unsigned __int8 byte_1170;
	unsigned __int8 byte_1171;
	unsigned __int8 byte_1172;
	unsigned __int8 byte_1173;
	unsigned __int8 byte_1174;
	unsigned __int8 byte_1175;
	unsigned __int8 byte_1176;
	unsigned __int8 byte_1177;
	unsigned __int8 byte_1178;
	unsigned __int8 byte_1179;
	unsigned __int8 byte_1180;
	unsigned __int8 byte_1181;
	unsigned __int8 byte_1182;
	unsigned __int8 byte_1183;
	unsigned __int8 byte_1184;
	unsigned __int8 byte_1185;
	unsigned __int8 byte_1186;
	unsigned __int8 byte_1187;
	unsigned __int8 byte_1188;
	unsigned __int8 byte_1189;
	unsigned __int8 byte_1190;
	unsigned __int8 byte_1191;
	unsigned __int8 byte_1192;
	unsigned __int8 byte_1193;
	unsigned __int8 byte_1194;
	unsigned __int8 byte_1195;
	unsigned __int8 byte_1196;
	unsigned __int8 byte_1197;
	unsigned __int8 byte_1198;
	unsigned __int8 byte_1199;
	unsigned __int8 byte_1200;
	unsigned __int8 byte_1201;
	unsigned __int8 byte_1202;
	unsigned __int8 byte_1203;
	unsigned __int8 byte_1204;
	unsigned __int8 byte_1205;
	unsigned __int8 byte_1206;
	unsigned __int8 byte_1207;
	unsigned __int8 byte_1208;
	unsigned __int8 byte_1209;
	unsigned __int8 byte_1210;
	unsigned __int8 byte_1211;
	unsigned __int8 byte_1212;
	unsigned __int8 byte_1213;
	unsigned __int8 byte_1214;
	unsigned __int8 byte_1215;
	unsigned __int8 byte_1216;
	unsigned __int8 byte_1217;
	unsigned __int8 byte_1218;
	unsigned __int8 byte_1219;
	unsigned __int8 byte_1220;
	unsigned __int8 byte_1221;
	unsigned __int8 byte_1222;
	unsigned __int8 byte_1223;
	unsigned __int8 byte_1224;
	unsigned __int8 byte_1225;
	unsigned __int8 byte_1226;
	unsigned __int8 byte_1227;
	unsigned __int8 byte_1228;
	unsigned __int8 byte_1229;
	unsigned __int8 byte_1230;
	unsigned __int8 byte_1231;
	unsigned __int8 byte_1232;
	unsigned __int8 byte_1233;
	unsigned __int8 byte_1234;
	unsigned __int8 byte_1235;
	unsigned __int8 byte_1236;
	unsigned __int8 byte_1237;
	unsigned __int8 byte_1238;
	unsigned __int8 byte_1239;
	unsigned __int8 byte_1240;
	unsigned __int8 byte_1241;
	unsigned __int8 byte_1242;
	unsigned __int8 byte_1243;
	unsigned __int8 byte_1244;
	unsigned __int8 byte_1245;
	unsigned __int8 byte_1246;
	unsigned __int8 byte_1247;
	unsigned __int8 byte_1248;
	unsigned __int8 byte_1249;
	unsigned __int8 byte_1250;
	unsigned __int8 byte_1251;
	unsigned __int8 byte_1252;
	unsigned __int8 byte_1253;
	unsigned __int8 byte_1254;
	unsigned __int8 byte_1255;
	unsigned __int8 byte_1256;
	unsigned __int8 byte_1257;
	unsigned __int8 byte_1258;
	unsigned __int8 byte_1259;
	unsigned __int8 byte_1260;
	unsigned __int8 byte_1261;
	unsigned __int8 byte_1262;
	unsigned __int8 byte_1263;
	unsigned __int8 byte_1264;
	unsigned __int8 byte_1265;
	unsigned __int8 byte_1266;
	unsigned __int8 byte_1267;
	unsigned __int8 byte_1268;
	unsigned __int8 byte_1269;
	unsigned __int8 byte_1270;
	unsigned __int8 byte_1271;
	unsigned __int8 byte_1272;
	unsigned __int8 byte_1273;
	unsigned __int8 byte_1274;
	unsigned __int8 byte_1275;
	unsigned __int8 byte_1276;
	unsigned __int8 byte_1277;
	unsigned __int8 byte_1278;
	unsigned __int8 byte_1279;
	unsigned __int8 byte_1280;
	unsigned __int8 byte_1281;
	unsigned __int8 byte_1282;
	unsigned __int8 byte_1283;
	unsigned __int8 byte_1284;
	unsigned __int8 byte_1285;
	unsigned __int8 byte_1286;
	unsigned __int8 byte_1287;
	unsigned __int8 byte_1288;
	unsigned __int8 byte_1289;
	unsigned __int8 byte_1290;
	unsigned __int8 byte_1291;
	unsigned __int8 byte_1292;
	unsigned __int8 byte_1293;
	unsigned __int8 byte_1294;
	unsigned __int8 byte_1295;
	unsigned __int8 byte_1296;
	unsigned __int8 byte_1297;
	unsigned __int8 byte_1298;
	unsigned __int8 byte_1299;
	unsigned __int8 byte_1300;
	unsigned __int8 byte_1301;
	unsigned __int8 byte_1302;
	unsigned __int8 byte_1303;
	unsigned __int8 byte_1304;
	unsigned __int8 byte_1305;
	unsigned __int8 byte_1306;
	unsigned __int8 byte_1307;
	unsigned __int8 byte_1308;
	unsigned __int8 byte_1309;
	unsigned __int8 byte_1310;
	unsigned __int8 byte_1311;
	unsigned __int8 byte_1312;
	unsigned __int8 Quest[12];
	char LastConnTime;
	char field_52D;
	char field_52E;
	char field_52F;
	char field_530;
	char field_531;
	char field_532;
	char field_533;
	char field_534;
	char field_535;
	char field_536;
	char field_537;
	char byte_1337;
	char field_539;
	char field_53A;
	char field_53B;
	unsigned __int8 byte_1341;
	unsigned __int8 byte_1342;
	unsigned __int8 byte_1343;
	unsigned __int8 byte_1344;
	unsigned __int8 byte_1345;
	unsigned __int8 byte_1346;
	unsigned __int8 byte_1347;
	unsigned __int8 byte_1348;
	unsigned __int8 byte_1349;
	unsigned __int8 byte_1350;
	unsigned __int8 byte_1351;
	unsigned __int8 byte_1352;
	unsigned __int8 byte_1353;
	unsigned __int8 byte_1354;
	unsigned __int8 byte_1355;
	unsigned __int8 byte_1356;
	unsigned __int8 byte_1357;
	unsigned __int8 byte_1358;
	unsigned __int8 byte_1359;
	unsigned __int8 byte_1360;
	unsigned __int8 byte_1361;
	unsigned __int8 byte_1362;
	unsigned __int8 byte_1363;
	unsigned __int8 byte_1364;
	unsigned __int8 byte_1365;
	unsigned __int8 byte_1366;
	unsigned __int8 byte_1367;
	unsigned __int8 byte_1368;
	unsigned __int8 byte_1369;
	unsigned __int8 byte_1370;
	unsigned __int8 byte_1371;
	unsigned __int8 byte_1372;
	unsigned __int8 byte_1373;
	unsigned __int8 byte_1374;
	unsigned __int8 byte_1375;
	unsigned __int8 byte_1376;
	unsigned __int8 byte_1377;
	unsigned __int8 byte_1378;
	unsigned __int8 byte_1379;
	unsigned __int8 byte_1380;
	unsigned __int8 byte_1381;
	unsigned __int8 byte_1382;
	unsigned __int8 byte_1383;
	unsigned __int8 byte_1384;
	unsigned __int8 byte_1385;
	unsigned __int8 byte_1386;
	unsigned __int8 byte_1387;
	unsigned __int8 byte_1388;
	unsigned __int8 byte_1389;
	unsigned __int8 byte_1390;
	unsigned __int8 byte_1391;
	unsigned __int8 byte_1392;
	unsigned __int8 byte_1393;
	unsigned __int8 byte_1394;
	unsigned __int8 byte_1395;
	unsigned __int8 byte_1396;
	unsigned __int8 byte_1397;
	unsigned __int8 byte_1398;
	unsigned __int8 byte_1399;
	unsigned __int8 byte_1400;
	unsigned __int8 byte_1401;
	unsigned __int8 byte_1402;
	unsigned __int8 byte_1403;
	unsigned __int8 byte_1404;
	unsigned __int8 byte_1405;
	unsigned __int8 byte_1406;
	unsigned __int8 byte_1407;
	unsigned __int8 byte_1408;
	unsigned __int8 byte_1409;
	unsigned __int8 byte_1410;
	unsigned __int8 byte_1411;
	unsigned __int8 byte_1412;
	unsigned __int8 byte_1413;
	unsigned __int8 byte_1414;
	unsigned __int8 byte_1415;
	unsigned __int8 byte_1416;
	unsigned __int8 byte_1417;
	unsigned __int8 byte_1418;
	unsigned __int8 byte_1419;
	unsigned __int8 byte_1420;
	unsigned __int8 byte_1421;
	unsigned __int8 byte_1422;
	unsigned __int8 byte_1423;
	unsigned __int8 byte_1424;
	unsigned __int8 byte_1425;
	unsigned __int8 byte_1426;
	unsigned __int8 byte_1427;
	unsigned __int8 byte_1428;
	unsigned __int8 byte_1429;
	unsigned __int8 byte_1430;
	unsigned __int8 byte_1431;
	unsigned __int8 byte_1432;
	unsigned __int8 byte_1433;
	unsigned __int8 byte_1434;
	unsigned __int8 byte_1435;
	unsigned __int8 byte_1436;
	unsigned __int8 byte_1437;
	unsigned __int8 byte_1438;
	unsigned __int8 byte_1439;
	unsigned __int8 byte_1440;
	unsigned __int8 byte_1441;
	unsigned __int8 byte_1442;
	unsigned __int8 byte_1443;
	unsigned __int8 byte_1444;
	unsigned __int8 byte_1445;
	unsigned __int8 byte_1446;
	unsigned __int8 byte_1447;
	unsigned __int8 byte_1448;
	unsigned __int8 byte_1449;
	unsigned __int8 byte_1450;
	unsigned __int8 byte_1451;
	unsigned __int8 byte_1452;
	unsigned __int8 byte_1453;
	unsigned __int8 byte_1454;
	unsigned __int8 byte_1455;
	unsigned __int8 byte_1456;
	unsigned __int8 byte_1457;
	unsigned __int8 byte_1458;
	unsigned __int8 byte_1459;
	unsigned __int8 byte_1460;
	unsigned __int8 byte_1461;
	unsigned __int8 byte_1462;
	unsigned __int8 byte_1463;
	unsigned __int8 byte_1464;
	unsigned __int8 byte_1465;
	unsigned __int8 byte_1466;
	unsigned __int8 byte_1467;
	unsigned __int8 byte_1468;
	unsigned __int8 byte_1469;
	unsigned __int8 byte_1470;
	unsigned __int8 byte_1471;
	unsigned __int8 byte_1472;
	unsigned __int8 byte_1473;
	unsigned __int8 byte_1474;
	unsigned __int8 byte_1475;
	unsigned __int8 byte_1476;
	unsigned __int8 byte_1477;
	unsigned __int8 byte_1478;
	unsigned __int8 byte_1479;
	unsigned __int8 byte_1480;
	unsigned __int8 byte_1481;
	unsigned __int8 byte_1482;
	unsigned __int8 byte_1483;
	unsigned __int8 byte_1484;
	unsigned __int8 byte_1485;
	unsigned __int8 byte_1486;
	unsigned __int8 byte_1487;
	unsigned __int8 byte_1488;
	unsigned __int8 byte_1489;
	unsigned __int8 byte_1490;
	unsigned __int8 byte_1491;
	unsigned __int8 byte_1492;
	unsigned __int8 byte_1493;
	unsigned __int8 byte_1494;
	unsigned __int8 byte_1495;
	unsigned __int8 byte_1496;
	unsigned __int8 byte_1497;
	unsigned __int8 byte_1498;
	unsigned __int8 byte_1499;
	unsigned __int8 byte_1500;
	unsigned __int8 byte_1501;
	unsigned __int8 byte_1502;
	unsigned __int8 byte_1503;
	unsigned __int8 byte_1504;
	unsigned __int8 byte_1505;
	unsigned __int8 byte_1506;
	unsigned __int8 byte_1507;
	unsigned __int8 byte_1508;
	unsigned __int8 byte_1509;
	unsigned __int8 byte_1510;
	unsigned __int8 byte_1511;
	unsigned __int8 byte_1512;
	unsigned __int8 byte_1513;
	unsigned __int8 byte_1514;
	unsigned __int8 byte_1515;
	unsigned __int8 byte_1516;
	unsigned __int8 byte_1517;
	unsigned __int8 byte_1518;
	unsigned __int8 byte_1519;
	unsigned __int8 byte_1520;
	unsigned __int8 byte_1521;
	unsigned __int8 byte_1522;
	unsigned __int8 byte_1523;
	unsigned __int8 byte_1524;
	unsigned __int8 byte_1525;
	unsigned __int8 byte_1526;
	unsigned __int8 byte_1527;
	unsigned __int8 byte_1528;
	unsigned __int8 byte_1529;
	unsigned __int8 byte_1530;
	unsigned __int8 byte_1531;
	unsigned __int8 byte_1532;
	unsigned __int8 byte_1533;
	unsigned __int8 byte_1534;
	unsigned __int8 byte_1535;
	unsigned __int8 byte_1536;
	unsigned __int8 byte_1537;
	unsigned __int8 byte_1538;
	unsigned __int8 byte_1539;
	unsigned __int8 byte_1540;
	unsigned __int8 byte_1541;
	unsigned __int8 byte_1542;
	unsigned __int8 byte_1543;
	unsigned __int8 byte_1544;
	unsigned __int8 byte_1545;
	unsigned __int8 byte_1546;
	unsigned __int8 byte_1547;
	unsigned __int8 byte_1548;
	unsigned __int8 byte_1549;
	unsigned __int8 byte_1550;
	unsigned __int8 byte_1551;
	unsigned __int8 byte_1552;
	unsigned __int8 byte_1553;
	unsigned __int8 byte_1554;
	unsigned __int8 byte_1555;
	unsigned __int8 byte_1556;
	unsigned __int8 byte_1557;
	unsigned __int8 byte_1558;
	unsigned __int8 byte_1559;
	unsigned __int8 byte_1560;
	unsigned __int8 byte_1561;
	unsigned __int8 byte_1562;
	unsigned __int8 byte_1563;
	unsigned __int8 byte_1564;
	unsigned __int8 byte_1565;
	unsigned __int8 byte_1566;
	unsigned __int8 byte_1567;
	unsigned __int8 byte_1568;
	unsigned __int8 byte_1569;
	unsigned __int8 byte_1570;
	unsigned __int8 byte_1571;
	unsigned __int8 byte_1572;
	unsigned __int8 byte_1573;
	unsigned __int8 byte_1574;
	unsigned __int8 byte_1575;
	unsigned __int8 byte_1576;
	unsigned __int8 byte_1577;
	unsigned __int8 byte_1578;
	unsigned __int8 byte_1579;
	unsigned __int8 byte_1580;
	unsigned __int8 byte_1581;
	unsigned __int8 byte_1582;
	unsigned __int8 byte_1583;
	unsigned __int8 byte_1584;
	unsigned __int8 byte_1585;
	unsigned __int8 byte_1586;
	unsigned __int8 byte_1587;
	unsigned __int8 byte_1588;
	unsigned __int8 byte_1589;
	unsigned __int8 byte_1590;
	unsigned __int8 byte_1591;
	unsigned __int8 byte_1592;
	unsigned __int8 byte_1593;
	unsigned __int8 byte_1594;
	unsigned __int8 byte_1595;
	unsigned __int8 byte_1596;
	unsigned __int8 byte_1597;
	unsigned __int8 byte_1598;
	unsigned __int8 byte_1599;
	unsigned __int8 byte_1600;
	unsigned __int8 byte_1601;
	unsigned __int8 byte_1602;
	unsigned __int8 byte_1603;
	unsigned __int8 byte_1604;
	unsigned __int8 byte_1605;
	unsigned __int8 byte_1606;
	unsigned __int8 byte_1607;
	unsigned __int8 byte_1608;
	unsigned __int8 byte_1609;
	unsigned __int8 byte_1610;
	unsigned __int8 byte_1611;
	unsigned __int8 byte_1612;
	unsigned __int8 byte_1613;
	unsigned __int8 byte_1614;
	unsigned __int8 byte_1615;
	unsigned __int8 byte_1616;
	unsigned __int8 byte_1617;
	unsigned __int8 byte_1618;
	unsigned __int8 byte_1619;
	unsigned __int8 byte_1620;
	unsigned __int8 byte_1621;
	unsigned __int8 byte_1622;
	unsigned __int8 byte_1623;
	unsigned __int8 byte_1624;
	unsigned __int8 byte_1625;
	unsigned __int8 byte_1626;
	unsigned __int8 byte_1627;
	unsigned __int8 byte_1628;
	unsigned __int8 byte_1629;
	unsigned __int8 byte_1630;
	unsigned __int8 byte_1631;
	unsigned __int8 byte_1632;
	unsigned __int8 byte_1633;
	unsigned __int8 byte_1634;
	unsigned __int8 byte_1635;
	unsigned __int8 byte_1636;
	unsigned __int8 byte_1637;
	unsigned __int8 byte_1638;
	unsigned __int8 byte_1639;
	unsigned __int8 byte_1640;
	unsigned __int8 byte_1641;
	unsigned __int8 byte_1642;
	unsigned __int8 byte_1643;
	unsigned __int8 byte_1644;
	unsigned __int8 byte_1645;
	unsigned __int8 byte_1646;
	unsigned __int8 byte_1647;
	unsigned __int8 byte_1648;
	unsigned __int8 byte_1649;
	unsigned __int8 byte_1650;
	unsigned __int8 byte_1651;
	unsigned __int8 byte_1652;
	unsigned __int8 byte_1653;
	unsigned __int8 byte_1654;
	unsigned __int8 byte_1655;
	unsigned __int8 byte_1656;
	unsigned __int8 byte_1657;
	unsigned __int8 byte_1658;
	unsigned __int8 byte_1659;
	unsigned __int8 byte_1660;
	unsigned __int8 byte_1661;
	unsigned __int8 byte_1662;
	unsigned __int8 byte_1663;
	unsigned __int8 byte_1664;
	unsigned __int8 byte_1665;
	unsigned __int8 byte_1666;
	unsigned __int8 byte_1667;
	unsigned __int8 byte_1668;
	unsigned __int8 byte_1669;
	unsigned __int8 byte_1670;
	unsigned __int8 byte_1671;
	unsigned __int8 byte_1672;
	STRUCT_AFFECT Affects[32];
	unsigned __int8 byte_1929;
	unsigned __int8 byte_1930;
	unsigned __int8 byte_1931;
	unsigned __int8 byte_1932;
	unsigned __int8 byte_1933;
	unsigned __int8 byte_1934;
	unsigned __int8 byte_1935;
	unsigned __int8 byte_1936;
	unsigned __int8 byte_1937;
	unsigned __int8 byte_1938;
	unsigned __int8 byte_1939;
	unsigned __int8 byte_1940;
	unsigned __int8 byte_1941;
	unsigned __int8 byte_1942;
	unsigned __int8 byte_1943;
	unsigned __int8 byte_1944;
	unsigned __int8 byte_1945;
	unsigned __int8 byte_1946;
	unsigned __int8 byte_1947;
	unsigned __int8 byte_1948;
	unsigned __int8 byte_1949;
	unsigned __int8 byte_1950;
	unsigned __int8 byte_1951;
	unsigned __int8 byte_1952;
	unsigned __int8 byte_1953;
	unsigned __int8 byte_1954;
	unsigned __int8 byte_1955;
	unsigned __int8 byte_1956;
	unsigned __int8 byte_1957;
	unsigned __int8 byte_1958;
	unsigned __int8 byte_1959;
	unsigned __int8 byte_1960;
	unsigned __int8 byte_1961;
	unsigned __int8 byte_1962;
	unsigned __int8 byte_1963;
	unsigned __int8 byte_1964;
	unsigned __int8 byte_1965;
	unsigned __int8 byte_1966;
	unsigned __int8 byte_1967;
	unsigned __int8 byte_1968;
	unsigned __int8 byte_1969;
	unsigned __int8 byte_1970;
	unsigned __int8 byte_1971;
	unsigned __int8 byte_1972;
	unsigned __int8 byte_1973;
	unsigned __int8 byte_1974;
	unsigned __int8 byte_1975;
	unsigned __int8 byte_1976;
	unsigned __int8 byte_1977;
	unsigned __int8 byte_1978;
	unsigned __int8 byte_1979;
	unsigned __int8 byte_1980;
	unsigned __int8 byte_1981;
	unsigned __int8 byte_1982;
	unsigned __int8 byte_1983;
	unsigned __int8 byte_1984;
	unsigned __int8 byte_1985;
	unsigned __int8 byte_1986;
	unsigned __int8 byte_1987;
	unsigned __int8 byte_1988;
	unsigned __int8 byte_1989;
	unsigned __int8 byte_1990;
	unsigned __int8 byte_1991;
	unsigned __int8 byte_1992;
	unsigned __int8 byte_1993;
	unsigned __int8 byte_1994;
	unsigned __int8 byte_1995;
	unsigned __int8 byte_1996;
	unsigned __int8 byte_1997;
	unsigned __int8 byte_1998;
	unsigned __int8 byte_1999;
	unsigned __int8 byte_2000;
	unsigned __int8 byte_2001;
	unsigned __int8 byte_2002;
	unsigned __int8 byte_2003;
	unsigned __int8 byte_2004;
	unsigned __int8 byte_2005;
	unsigned __int8 byte_2006;
	unsigned __int8 byte_2007;
	unsigned __int8 byte_2008;
	unsigned __int8 byte_2009;
	unsigned __int8 byte_2010;
	unsigned __int8 byte_2011;
	unsigned __int8 byte_2012;
	unsigned __int8 byte_2013;
	unsigned __int8 byte_2014;
	unsigned __int8 byte_2015;
	unsigned __int8 byte_2016;
	unsigned __int8 byte_2017;
	unsigned __int8 byte_2018;
	unsigned __int8 byte_2019;
	unsigned __int8 byte_2020;
	unsigned __int8 byte_2021;
	unsigned __int8 byte_2022;
	unsigned __int8 byte_2023;
	unsigned __int8 byte_2024;
	unsigned __int8 byte_2025;
	unsigned __int8 byte_2026;
	unsigned __int8 byte_2027;
	unsigned __int8 byte_2028;
	unsigned __int8 byte_2029;
	unsigned __int8 byte_2030;
	unsigned __int8 byte_2031;
	unsigned __int8 byte_2032;
	unsigned __int8 byte_2033;
	unsigned __int8 byte_2034;
	unsigned __int8 byte_2035;
	unsigned __int8 byte_2036;
	unsigned __int8 byte_2037;
	unsigned __int8 byte_2038;
	unsigned __int8 byte_2039;
	unsigned __int8 byte_2040;
	unsigned __int8 byte_2041;
	unsigned __int8 byte_2042;
	unsigned __int8 byte_2043;
	unsigned __int8 byte_2044;
	int GenerateIndex;
	unsigned __int8 byte_2049;
	unsigned __int8 byte_2050;
	unsigned __int8 byte_2051;
	unsigned __int8 byte_2052;
	unsigned __int8 byte_2053;
	unsigned __int8 byte_2054;
	unsigned __int8 byte_2055;
	unsigned __int8 byte_2056;
	unsigned __int8 byte_2057;
	unsigned __int8 byte_2058;
	unsigned __int8 byte_2059;
	unsigned __int8 byte_2060;
	unsigned __int8 byte_2061;
	unsigned __int8 byte_2062;
	unsigned __int8 byte_2063;
	unsigned __int8 byte_2064;
	unsigned __int8 byte_2065;
	unsigned __int8 byte_2066;
	unsigned __int8 byte_2067;
	unsigned __int8 byte_2068;
	unsigned __int8 byte_2069;
	unsigned __int8 byte_2070;
	unsigned __int8 byte_2071;
	unsigned __int8 byte_2072;
	unsigned __int8 byte_2073;
	unsigned __int8 byte_2074;
	unsigned __int8 byte_2075;
	unsigned __int8 byte_2076;
	unsigned __int8 byte_2077;
	unsigned __int8 byte_2078;
	unsigned __int8 byte_2079;
	unsigned __int8 byte_2080;
	unsigned __int8 byte_2081;
	unsigned __int8 byte_2082;
	unsigned __int8 byte_2083;
	unsigned __int8 byte_2084;
	int byte_2085;
	DWORD PartyLeader;
	unsigned __int8 byte_2093;
	unsigned __int8 byte_2094;
	unsigned __int8 byte_2095;
	unsigned __int8 byte_2096;
	unsigned __int8 byte_2097;
	unsigned __int8 byte_2098;
	unsigned __int8 byte_2099;
	unsigned __int8 byte_2100;
	int OtherPosX;
	int OtherPosY;
	unsigned __int8 byte_2109;
	unsigned __int8 byte_2110;
	unsigned __int8 byte_2111;
	unsigned __int8 byte_2112;
	unsigned __int8 byte_2113;
	unsigned __int8 byte_2114;
	unsigned __int8 byte_2115;
	unsigned __int8 byte_2116;
	int PosX;
	int PosY;
	unsigned __int8 byte_2125;
	unsigned __int8 byte_2126;
	unsigned __int8 byte_2127;
	unsigned __int8 byte_2128;
	unsigned __int8 byte_2129;
	unsigned __int8 byte_2130;
	unsigned __int8 byte_2131;
	unsigned __int8 byte_2132;
	unsigned __int8 byte_2133;
	unsigned __int8 byte_2134;
	unsigned __int8 byte_2135;
	unsigned __int8 byte_2136;
	unsigned __int8 byte_2137;
	unsigned __int8 byte_2138;
	unsigned __int8 byte_2139;
	unsigned __int8 byte_2140;
	unsigned __int8 byte_2141;
	unsigned __int8 byte_2142;
	unsigned __int8 byte_2143;
	unsigned __int8 byte_2144;
	unsigned __int8 byte_2145;
	unsigned __int8 byte_2146;
	unsigned __int8 byte_2147;
	unsigned __int8 byte_2148;
	unsigned __int8 byte_2149;
	unsigned __int8 byte_2150;
	unsigned __int8 byte_2151;
	unsigned __int8 byte_2152;
	unsigned __int8 byte_2153;
	unsigned __int8 byte_2154;
	unsigned __int8 byte_2155;
	unsigned __int8 byte_2156;
	unsigned __int8 byte_2157;
	unsigned __int8 byte_2158;
	unsigned __int8 byte_2159;
	unsigned __int8 byte_2160;
	unsigned __int8 byte_2161;
	unsigned __int8 byte_2162;
	unsigned __int8 byte_2163;
	unsigned __int8 byte_2164;
	unsigned __int8 byte_2165;
	unsigned __int8 byte_2166;
	unsigned __int8 byte_2167;
	unsigned __int8 byte_2168;
	DWORD SummonerID;
	unsigned __int8 byte_2173;
	unsigned __int8 byte_2174;
	unsigned __int8 byte_2175;
	unsigned __int8 byte_2176;
	int GuildFlag;
	unsigned __int8 byte_2181;
	unsigned __int8 byte_2182;
	unsigned __int8 byte_2183;
	unsigned __int8 byte_2184;
	int ExpBonus;
	unsigned __int8 byte_2189;
	unsigned __int8 byte_2190;
	unsigned __int8 byte_2191;
	unsigned __int8 byte_2192;
	unsigned __int8 byte_2193;
	unsigned __int8 byte_2194;
	unsigned __int8 byte_2195;
	unsigned __int8 byte_2196;
	unsigned __int8 byte_2197;
	unsigned __int8 byte_2198;
	unsigned __int8 byte_2199;
	unsigned __int8 byte_2200;
	unsigned __int8 byte_2201;
	unsigned __int8 byte_2202;
	unsigned __int8 byte_2203;
	unsigned __int8 byte_2204;
	unsigned __int8 byte_2205;
	unsigned __int8 byte_2206;
	unsigned __int8 byte_2207;
	unsigned __int8 byte_2208;
	DWORD byte_2209;
	unsigned __int8 byte_2213;
	unsigned __int8 byte_2214;
	unsigned __int8 byte_2215;
	unsigned __int8 byte_2216;
	unsigned __int8 byte_2217;
	unsigned __int8 byte_2218;
	unsigned __int8 byte_2219;
	unsigned __int8 byte_2220;
	unsigned __int8 byte_2221;
	unsigned __int8 byte_2222;
	unsigned __int8 byte_2223;
	unsigned __int8 byte_2224;
	unsigned __int8 byte_2225;
	unsigned __int8 byte_2226;
	unsigned __int8 byte_2227;
	unsigned __int8 byte_2228;
	unsigned __int8 byte_2229;
	unsigned __int8 byte_2230;
	unsigned __int8 byte_2231;
	unsigned __int8 byte_2232;
	unsigned __int8 byte_2233;
	unsigned __int8 byte_2234;
	unsigned __int8 byte_2235;
	unsigned __int8 byte_2236;
	int TmpGuild;
	int TmpClan;
	unsigned __int8 byte_2245;
	unsigned __int8 byte_2246;
	unsigned __int8 byte_2247;
	unsigned __int8 byte_2248;
	unsigned __int8 byte_2249;
	unsigned __int8 byte_2250;
	unsigned __int8 byte_2251;
	unsigned __int8 byte_2252;
	unsigned __int8 byte_2253;
	unsigned __int8 byte_2254;
	unsigned __int8 byte_2255;
	unsigned __int8 byte_2256;
	unsigned __int8 byte_2257;
	unsigned __int8 byte_2258;
	unsigned __int8 byte_2259;
	unsigned __int8 byte_2260;
	unsigned __int8 byte_2261;
	unsigned __int8 byte_2262;
	unsigned __int8 byte_2263;
	unsigned __int8 byte_2264;
	unsigned __int8 byte_2265;
	unsigned __int8 byte_2266;
	unsigned __int8 byte_2267;
	unsigned __int8 byte_2268;
	unsigned __int8 byte_2269;
	unsigned __int8 byte_2270;
	unsigned __int8 byte_2271;
	unsigned __int8 byte_2272;
	unsigned __int8 byte_2273;
	unsigned __int8 byte_2274;
	unsigned __int8 byte_2275;
	unsigned __int8 byte_2276;
	unsigned __int8 byte_2277;
	unsigned __int8 byte_2278;
	unsigned __int8 byte_2279;
	unsigned __int8 byte_2280;
	unsigned __int8 byte_2281;
	unsigned __int8 byte_2282;
	unsigned __int8 byte_2283;
	unsigned __int8 byte_2284;
	unsigned __int8 byte_2285;
	unsigned __int8 byte_2286;
	unsigned __int8 byte_2287;
	unsigned __int8 byte_2288;
	unsigned __int8 byte_2289;
	unsigned __int8 byte_2290;
	unsigned __int8 byte_2291;
	unsigned __int8 byte_2292;
	unsigned __int8 byte_2293;
	unsigned __int8 byte_2294;
	unsigned __int8 byte_2295;
	unsigned __int8 byte_2296;
	unsigned __int8 byte_2297;
	unsigned __int8 byte_2298;
	unsigned __int8 byte_2299;
	unsigned __int8 byte_2300;
	unsigned __int8 byte_2301;
	unsigned __int8 byte_2302;
	unsigned __int8 byte_2303;
	unsigned __int8 byte_2304;
	unsigned __int8 byte_2305;
	unsigned __int8 byte_2306;
	unsigned __int8 byte_2307;
	unsigned __int8 byte_2308;
	unsigned __int8 byte_2309;
	unsigned __int8 byte_2310;
	unsigned __int8 byte_2311;
	unsigned __int8 byte_2312;
	unsigned __int8 byte_2313;
	unsigned __int8 byte_2314;
	unsigned __int8 byte_2315;
	unsigned __int8 byte_2316;
	unsigned __int8 byte_2317;
	unsigned __int8 byte_2318;
	unsigned __int8 byte_2319;
	unsigned __int8 byte_2320;
	unsigned __int8 byte_2321;
	unsigned __int8 byte_2322;
	unsigned __int8 byte_2323;
	unsigned __int8 byte_2324;
	unsigned __int8 byte_2325;
	unsigned __int8 byte_2326;
	unsigned __int8 byte_2327;
	unsigned __int8 byte_2328;
	unsigned __int8 byte_2329;
	unsigned __int8 byte_2330;
	unsigned __int8 byte_2331;
	unsigned __int8 byte_2332;
	unsigned __int8 byte_2333;
	unsigned __int8 byte_2334;
	unsigned __int8 byte_2335;
	unsigned __int8 byte_2336;
	unsigned __int8 byte_2337;
	unsigned __int8 byte_2338;
	unsigned __int8 byte_2339;
	unsigned __int8 byte_2340;
	unsigned __int8 byte_2341;
	unsigned __int8 byte_2342;
	unsigned __int8 byte_2343;
	unsigned __int8 byte_2344;
};