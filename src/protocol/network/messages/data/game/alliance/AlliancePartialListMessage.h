#ifndef ALLIANCEPARTIALLISTMESSAGE_H
#define ALLIANCEPARTIALLISTMESSAGE_H

#include "src/protocol/network/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/alliance/AllianceListMessage.h"

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