#ifndef SERVERSESSIONCONSTANT_H
#define SERVERSESSIONCONSTANT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ServerSessionConstant : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSessionConstant(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSessionConstant(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSessionConstant(FuncTree tree);
  ServerSessionConstant();
  bool operator==(const ServerSessionConstant &compared);

  uint id;

private:
  void _idFunc(Reader *input);
};

#endif // SERVERSESSIONCONSTANT_H