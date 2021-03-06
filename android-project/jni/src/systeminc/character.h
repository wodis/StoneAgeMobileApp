#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include"action.h"
#include"pc.h"

enum
{
	CHR_STATUS_P 		= 0x0001,			// ��
	CHR_STATUS_N 		= 0x0002,			// ??
	CHR_STATUS_Q 		= 0x0004,			// ��?
	CHR_STATUS_S 		= 0x0008,			// ��?
	CHR_STATUS_D 		= 0x0010,			// ??
	CHR_STATUS_C 		= 0x0020,			// ??
	CHR_STATUS_W 		= 0x0040,			// ??��?��???
	CHR_STATUS_H 		= 0x0080,			// ??????
	CHR_STATUS_LEADER	= 0x0100,			// ????
	CHR_STATUS_PARTY	= 0x0200,			// ???????
	CHR_STATUS_BATTLE	= 0x0400,			// �P�f?
	CHR_STATUS_USE_MAGIC= 0x0800,			// ������?
	CHR_STATUS_HELP		= 0x1000,			// ???
	CHR_STATUS_FUKIDASHI= 0x2000,			// ??��?
	CHR_STATUS_WATCH	= 0x4000,			// ?�P?
	CHR_STATUS_TRADE	= 0x8000,			// ������
#ifdef _ANGEL_SUMMON
	CHR_STATUS_ANGEL	= 0x10000			// ʹ��������
#endif
};

enum
{											// ???????��?
	CHAROBJ_TYPE_NPC		= 0x0001,		// NPC
	CHAROBJ_TYPE_ITEM		= 0x0002,		// ????
	CHAROBJ_TYPE_MONEY		= 0x0004,		// ??
	CHAROBJ_TYPE_USER_NPC	= 0x0008,		// �\��??????
	CHAROBJ_TYPE_LOOKAT		= 0x0010,		// ???
	CHAROBJ_TYPE_PARTY_OK	= 0x0020,		// ?????�V??
	CHAROBJ_TYPE_ALL		= 0x00FF		// �u?
};

// ???��????�k?
enum
{
	CHAR_TYPENONE,          // ?????
	CHAR_TYPEPLAYER,        // ?????
	CHAR_TYPEENEMY,         // ��
	CHAR_TYPEPET,           // ???
	CHAR_TYPEDOOR,          // ??
	CHAR_TYPEBOX ,          // ��?
	CHAR_TYPEMSG ,          // ?�Y
	CHAR_TYPEWARP ,         // ??????
	CHAR_TYPESHOP ,         // ��
	CHAR_TYPEHEALER ,       // ????
	CHAR_TYPEOLDMAN ,       // ��?
	CHAR_TYPEROOMADMIN,     // �ۥh��?
	CHAR_TYPETOWNPEOPLE,    // ?????
	CHAR_TYPEDENGON,        // ��?�\
	CHAR_TYPEADM,           // ��?�\
	CHAR_TYPETEMPLE,        // Temple master
	CHAR_TYPESTORYTELLER,   // ???
	CHAR_TYPERANKING,       // �ۥh��?????����???
	CHAR_TYPEOTHERNPC,      // ??�\???�n��?????NPC
	CHAR_TYPEPRINTPASSMAN,  // ????????����??NPC
	CHAR_TYPENPCENEMY,      // ?�e��
	CHAR_TYPEACTION,        // ??????�T???NPC
	CHAR_TYPEWINDOWMAN,     // ?????����??NPC??????)
	CHAR_TYPESAVEPOINT,     // ???????
	CHAR_TYPEWINDOWHEALER,  // ?????????????
	CHAR_TYPEITEMSHOP,      // ?��
	CHAR_TYPESTONESHOP,     // ��l?????????
	CHAR_TYPEDUELRANKING,   // DUEL?????NPC
	CHAR_TYPEWARPMAN,       // ?????NPC
	CHAR_TYPEEVENT,         // ????NPC
	CHAR_TYPEMIC,           // ????NPC
	CHAR_TYPELUCKYMAN,      // ????NPC
	CHAR_TYPEBUS,           // ??????
	CHAR_TYPECHARM,         // ????NPC
	CHAR_TYPENUM
};

typedef struct
{
	short use;				// ��???
	short type;				// ��?
	int id;					// ??????�k?
	int graNo;				// ??????�k?
	int gx, gy;				// ?????��
	int level;				// ???
	int dir;				// ??
	int stockDir;			// ?�h????��?????��???
	int stockDirX, stockDirY;// stockDir?��????��
	short nameColor;		// ���q����??��
#ifdef _ANGEL_SUMMON
	unsigned status;	// ?????
#else
	unsigned short status;	// ?????
#endif
	int classNo;			// ????????
	int money;				// ???
	char name[CHAR_NAME_LEN+1];			// ���q
	char freeName[CHAR_FREENAME_LEN+1];	// ????��??��?
	char info[64];			// ????????????ACTION?�V??????????
	int battleNo;			// �P�f�k?
	short sideNo;			// �P�f?????????�N?????
	short helpMode;			// ??????
	int charType;			// ??????�@�e??�N��
	short newFoundFlag;		// ���D???��?????????????
	ACTION *ptAct;
	int charNameColor;		// ???????????���q?��    
	// shan add
	char fmname[CHAR_FMNAME_LEN+1];    // ��������
	// Robin
	char petName[CHAR_FREENAME_LEN+1];
	int petLevel;

//#ifdef _CHAR_PROFESSION			// WON ADD ����ְҵ
//	int profession_class;
//#endif

} CHAROBJ;

typedef struct
{
	int charObjTblId;			// ????????�k??�V?????
	unsigned int drawFukidashiTime;	// ??��??��???
	ACTION *ptActLeaderMark;	// ???????����?
	ACTION *ptActMagicEffect;	// ����?????
#ifdef __EMOTION
	ACTION *ptActEmotion;
#endif
#ifdef _MIND_ICON
	ACTION *ptMindIcon;
#endif
#ifdef _STREET_VENDOR
	ACTION *ptStreetVendor;
#endif
#ifdef _ANGEL_SUMMON
	ACTION *ptActAngelMark;
#endif
#ifdef _ITEM_FIREWORK
	ACTION *pActFirework[2];
#endif
#ifdef _NPC_PICTURE
	ACTION *ptActPicture;
#endif
} CHAREXTRA;

typedef struct
{
	short mode;					// ????�h????
	short moveDir;				// ?�h?????��?
	short preDir;				// ???�q???????
	short dirCnt;				// ?�Q???????
	int preGx, preGy;			// ???�q?????
	int walkCnt;				// ?�h��?
	unsigned int createTime;	// ?��??
	ACTION *ptAct;
	ACTION *ptAct2;
	float angle;
	int r;
	int id;						// ??????�k?
} PETEXTRA;

extern short nameOverTheHeadFlag;

void charMove( ACTION * );
void charMove2( ACTION * );
void _charMove( ACTION * );
void shiftBufCount( ACTION * );

ACTION *createCharAction( int, int, int, int );

#ifdef _WATERANIMATION //Syu ADD ��֮��������
ACTION *createWaterAnimation( int , int , int , int );
#endif

void stockCharMovePoint( ACTION *, int, int );
void correctCharMovePoint( ACTION *, int, int );

void setCharMovePoint( ACTION *, int, int );
void _setCharMovePoint( ACTION *, int, int );
void setCharWarpPoint( ACTION *, int, int );
void setCharStatus( unsigned short *, char * );

ACTION *createCommmonEffectAction( int, int, int, int, int, int );
ACTION *createCommmonEffectNoLoop( int, int, int, int, int, int );
void drawCharStatus( ACTION * );

void changeCharAct( ACTION *, int, int, int, int, int, int, int );

void setCharLeader( ACTION * );
void delCharLeader( ACTION * );
void setCharParty( ACTION * );
void delCharParty( ACTION * );
void setCharWatch( ACTION * );
void delCharWatch( ACTION * );
void setCharBattle( ACTION *, int, short, short );
void delCharBattle( ACTION * );
void setCharTrade( ACTION *, int );
void delCharTrade( ACTION * );
void setCharUseMagic( ACTION * );
void delCharUseMagic( ACTION * );
#ifdef _ANGEL_SUMMON
void setCharAngel( ACTION * );
void delCharAngel( ACTION * );
#endif


#ifdef _MIND_ICON
void setCharMind( ACTION *ptAct, int MindNo);
void delCharMind( ACTION *ptAct);
#endif

void setCharFukidashi( ACTION *, unsigned int );
void setCharNameColor( ACTION *, int );


bool checkCharObjPoint( int, int, short );
#ifdef _ANGEL_SUMMON
int checkCharObjPointStatus( int, int, short, unsigned );
int checkCharObjPointNotStatus( int, int, short, unsigned );
#else
int checkCharObjPointStatus( int, int, short, unsigned short );
int checkCharObjPointNotStatus( int, int, short, unsigned short );
#endif

#ifdef _CHAR_PROFESSION			// WON ADD ����ְҵ
    #ifdef _GM_IDENTIFY		// Rog ADD GMʶ��
        void setNpcCharObj( int, int, int, int, int, char *, char *, char *, int, char *, int, int, int, int, int, int, char *);
    #else
		#ifdef _NPC_PICTURE
			void setNpcCharObj( int, int, int, int, int, char *, char *, char *, int, char *, int, int, int, int, int, int, int );
		#else
			void setNpcCharObj( int, int, int, int, int, char *, char *, char *, int, char *, int, int, int, int, int, int );
		#endif
    #endif
#else
    void setNpcCharObj( int, int, int, int, int, char *, char *, char *, int, char *, int, int, int, int, int);
#endif

bool setReturnPetObj( int, int, int, int, int, char *, char *, int, int, int, int, int );
void setItemCharObj( int, int, int, int, int, int, char * );
void setMoneyCharObj( int, int, int, int, int, int, char * );
int getAtrCharType( int );
int getAtrCharObjType( int );
void delCharObj( int );
void initCharObj( void );
void resetCharObj( void );
void clearPtActCharObj( void );
void restorePtActCharObjAll( void );
void restorePtActCharObj( int );
void setMovePointCharObj( int, int, int );
ACTION *getCharObjAct( int );

int getCharObjBuf( void );

void initItemOverlapCheck( void );
bool itemOverlapCheck( unsigned int, int, int );

ACTION *createPetAction( int, int, int, int, int, int, int );
void ajustClientDir( short * );

#endif
