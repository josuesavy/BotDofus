#ifndef BUFFERINFORMATION_H
#define BUFFERINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class BufferInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BufferInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BufferInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BufferInformation(FuncTree tree);
  BufferInformation();
  bool operator==(const BufferInformation &compared);

  double id;
  double amount;

private:
  void _idFunc(Reader *input);
  void _amountFunc(Reader *input);
};

#endif // BUFFERINFORMATION_H