#ifndef ALMANACHCALENDARDATEMESSAGE_H
#define ALMANACHCALENDARDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AlmanachCalendarDateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlmanachCalendarDateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlmanachCalendarDateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlmanachCalendarDateMessage(FuncTree tree);
  AlmanachCalendarDateMessage();

  int date;

private:
  void _dateFunc(Reader *input);
};

#endif // ALMANACHCALENDARDATEMESSAGE_H