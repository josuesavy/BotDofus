#ifndef TITLESELECTERRORMESSAGE_H
#define TITLESELECTERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TitleSelectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitleSelectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitleSelectErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitleSelectErrorMessage(FuncTree tree);
  TitleSelectErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // TITLESELECTERRORMESSAGE_H