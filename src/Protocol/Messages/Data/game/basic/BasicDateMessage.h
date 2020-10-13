#ifndef BASICDATEMESSAGE_H
#define BASICDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicDateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicDateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicDateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicDateMessage(FuncTree tree);
  BasicDateMessage();

  uint day;
  uint month;
  uint year;

private:
  void _dayFunc(Reader *input);
  void _monthFunc(Reader *input);
  void _yearFunc(Reader *input);
};

#endif // BASICDATEMESSAGE_H