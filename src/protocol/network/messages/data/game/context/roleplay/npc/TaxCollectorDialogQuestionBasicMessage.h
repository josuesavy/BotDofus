#ifndef TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H
#define TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorDialogQuestionBasicMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorDialogQuestionBasicMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorDialogQuestionBasicMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorDialogQuestionBasicMessage(FuncTree tree);
  TaxCollectorDialogQuestionBasicMessage();

  QSharedPointer<BasicAllianceInformations> allianceInfo;

private:
  void _allianceInfotreeFunc(Reader *input);

  FuncTree _allianceInfotree;
};

#endif // TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H