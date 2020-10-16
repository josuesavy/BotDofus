#ifndef ALLIANCEPARTIALLISTMESSAGE_H
#define ALLIANCEPARTIALLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/social/AllianceFactSheetInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/alliance/AllianceListMessage.h"

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