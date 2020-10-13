#ifndef TITLESELECTREQUESTMESSAGE_H
#define TITLESELECTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TitleSelectRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitleSelectRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitleSelectRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitleSelectRequestMessage(FuncTree tree);
  TitleSelectRequestMessage();

  uint titleId;

private:
  void _titleIdFunc(Reader *input);
};

#endif // TITLESELECTREQUESTMESSAGE_H