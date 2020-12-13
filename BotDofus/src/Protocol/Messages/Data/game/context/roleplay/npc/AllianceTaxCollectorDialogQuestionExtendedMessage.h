#ifndef ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H
#define ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/npc/TaxCollectorDialogQuestionExtendedMessage.h"

class AllianceTaxCollectorDialogQuestionExtendedMessage : public TaxCollectorDialogQuestionExtendedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceTaxCollectorDialogQuestionExtendedMessage(FuncTree tree);
  AllianceTaxCollectorDialogQuestionExtendedMessage();

  QSharedPointer<BasicNamedAllianceInformations> alliance;

private:
  void _alliancetreeFunc(Reader *input);

  FuncTree _alliancetree;
};

#endif // ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H