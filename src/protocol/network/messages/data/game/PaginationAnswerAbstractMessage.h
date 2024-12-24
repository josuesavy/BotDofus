#ifndef PAGINATIONANSWERABSTRACTMESSAGE_H
#define PAGINATIONANSWERABSTRACTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaginationAnswerAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaginationAnswerAbstractMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaginationAnswerAbstractMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaginationAnswerAbstractMessage(FuncTree tree);
  PaginationAnswerAbstractMessage();

  double offset;
  uint count;
  uint total;

private:
  void _offsetFunc(Reader *input);
  void _countFunc(Reader *input);
  void _totalFunc(Reader *input);
};

#endif // PAGINATIONANSWERABSTRACTMESSAGE_H