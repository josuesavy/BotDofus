#ifndef ALLIANCELISTMESSAGE_H
#define ALLIANCELISTMESSAGE_H

#include "src/Protocol/Types/Data/game/social/AllianceFactSheetInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceListMessage(FuncTree tree);
  AllianceListMessage();

  QList<QSharedPointer<AllianceFactSheetInformations>> alliances;

private:
  void _alliancestreeFunc(Reader *input);
  void _alliancesFunc(Reader *input);

  FuncTree _alliancestree;
};

#endif // ALLIANCELISTMESSAGE_H