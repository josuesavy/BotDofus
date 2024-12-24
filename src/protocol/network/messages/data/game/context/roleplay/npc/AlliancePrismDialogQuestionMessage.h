#ifndef ALLIANCEPRISMDIALOGQUESTIONMESSAGE_H
#define ALLIANCEPRISMDIALOGQUESTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AlliancePrismDialogQuestionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePrismDialogQuestionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePrismDialogQuestionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePrismDialogQuestionMessage(FuncTree tree);
  AlliancePrismDialogQuestionMessage();
};

#endif // ALLIANCEPRISMDIALOGQUESTIONMESSAGE_H