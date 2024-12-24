#ifndef TEXTINFORMATIONMESSAGE_H
#define TEXTINFORMATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TextInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TextInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TextInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TextInformationMessage(FuncTree tree);
  TextInformationMessage();

  uint msgType;
  uint msgId;
  QList<QString> parameters;

private:
  void _msgTypeFunc(Reader *input);
  void _msgIdFunc(Reader *input);
  void _parameterstreeFunc(Reader *input);
  void _parametersFunc(Reader *input);

  FuncTree _parameterstree;
};

#endif // TEXTINFORMATIONMESSAGE_H