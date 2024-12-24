#ifndef NPCDIALOGQUESTIONMESSAGE_H
#define NPCDIALOGQUESTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NpcDialogQuestionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NpcDialogQuestionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NpcDialogQuestionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NpcDialogQuestionMessage(FuncTree tree);
  NpcDialogQuestionMessage();

  uint messageId;
  QList<QString> dialogParams;
  QList<uint> visibleReplies;

private:
  void _messageIdFunc(Reader *input);
  void _dialogParamstreeFunc(Reader *input);
  void _dialogParamsFunc(Reader *input);
  void _visibleRepliestreeFunc(Reader *input);
  void _visibleRepliesFunc(Reader *input);

  FuncTree _dialogParamstree;
  FuncTree _visibleRepliestree;
};

#endif // NPCDIALOGQUESTIONMESSAGE_H