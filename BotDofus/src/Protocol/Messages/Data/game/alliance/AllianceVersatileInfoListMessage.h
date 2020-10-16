#ifndef ALLIANCEVERSATILEINFOLISTMESSAGE_H
#define ALLIANCEVERSATILEINFOLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/social/AllianceVersatileInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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