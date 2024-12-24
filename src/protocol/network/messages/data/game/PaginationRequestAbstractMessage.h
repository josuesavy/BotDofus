#ifndef PAGINATIONREQUESTABSTRACTMESSAGE_H
#define PAGINATIONREQUESTABSTRACTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaginationRequestAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaginationRequestAbstractMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaginationRequestAbstractMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaginationRequestAbstractMessage(FuncTree tree);
  PaginationRequestAbstractMessage();

  double offset;
  uint count;

private:
  void _offsetFunc(Reader *input);
  void _countFunc(Reader *input);
};

#endif // PAGINATIONREQUESTABSTRACTMESSAGE_H