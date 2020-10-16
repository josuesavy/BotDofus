#ifndef TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H
#define TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  QSharedPointer<BasicGuildInformations> guildInfo;

private:
  void _guildInfotreeFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H