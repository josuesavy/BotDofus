#ifndef ALLIANCEVERSATILEINFOLISTMESSAGE_H
#define ALLIANCEVERSATILEINFOLISTMESSAGE_H

#include "src/protocol/types/data/game/social/AllianceVersatileInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceVersatileInfoListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceVersatileInfoListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceVersatileInfoListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceVersatileInfoListMessage(FuncTree tree);
  AllianceVersatileInfoListMessage();

  QList<AllianceVersatileInformations> alliances;

private:
  void _alliancestreeFunc(Reader *input);
  void _alliancesFunc(Reader *input);

  FuncTree _alliancestree;
};

#endif // ALLIANCEVERSATILEINFOLISTMESSAGE_H