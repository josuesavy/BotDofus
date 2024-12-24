#ifndef EXCHANGESTARTOKJOBINDEXMESSAGE_H
#define EXCHANGESTARTOKJOBINDEXMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartOkJobIndexMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkJobIndexMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkJobIndexMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkJobIndexMessage(FuncTree tree);
  ExchangeStartOkJobIndexMessage();

  QList<uint> jobs;

private:
  void _jobstreeFunc(Reader *input);
  void _jobsFunc(Reader *input);

  FuncTree _jobstree;
};

#endif // EXCHANGESTARTOKJOBINDEXMESSAGE_H