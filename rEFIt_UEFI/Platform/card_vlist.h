/*
 * card_vlist.h
 *
 *  Created on: 16 Apr 2020
 *      Author: jief
 */

#ifndef PLATFORM_CARD_VLIST_H_
#define PLATFORM_CARD_VLIST_H_

#include "../Platform/plist/plist.h"


typedef struct {
  UINT32            Signature;
  LIST_ENTRY        Link;
  CHAR8             Model[64];
  UINT32            Id;
  UINT32            SubId;
  UINT64            VideoRam;
  UINTN             VideoPorts;
  BOOLEAN           LoadVBios;
} CARDLIST;


#define CARDLIST_SIGNATURE SIGNATURE_32('C','A','R','D')


void
FillCardList (
  const TagDict* CfgDict
  );

CARDLIST
*FindCardWithIds (
  UINT32 Id,
  UINT32 SubId
  );

void
AddCard (
  CONST CHAR8 *Model,
  UINT32      Id,
  UINT32      SubId,
  UINT64      VideoRam,
  UINTN       VideoPorts,
  BOOLEAN     LoadVBios
  );



#endif /* PLATFORM_CARD_VLIST_H_ */
