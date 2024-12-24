#ifndef REPORTRESPONSEMESSAGE_H
#define REPORTRESPONSEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ReportResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ReportResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ReportResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ReportResponseMessage(FuncTree tree);
  ReportResponseMessage();

  bool success;

private:
  void _successFunc(Reader *input);
};

#endif // REPORTRESPONSEMESSAGE_H