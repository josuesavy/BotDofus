#ifndef ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H
#define ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/npc/TaxCollectorDialogQuestionExtendedMessage.h"

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