#ifndef ALLIANCELISTMESSAGE_H
#define ALLIANCELISTMESSAGE_H

#include "src/protocol/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  QList<QSharedPointer<AllianceFactSheetInformation>> alliances;

private:
  void _alliancestreeFunc(Reader *input);
  void _alliancesFunc(Reader *input);

  FuncTree _alliancestree;
};

#endif // ALLIANCELISTMESSAGE_H