#ifndef ALLIANCEPARTIALLISTMESSAGE_H
#define ALLIANCEPARTIALLISTMESSAGE_H

#include "src/protocol/types/data/game/social/AllianceFactSheetInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/alliance/AllianceListMessage.h"

class AlliancePartialListMessage : public AllianceListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePartialListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePartialListMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePartialListMessage(FuncTree tree);
  AlliancePartialListMessage();
};

#endif // ALLIANCEPARTIALLISTMESSAGE_H