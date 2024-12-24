#ifndef UUID_H
#define UUID_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class Uuid : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Uuid(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Uuid(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Uuid(FuncTree tree);
  Uuid();
  bool operator==(const Uuid &compared);

  QString uuidString;

private:
  void _uuidStringFunc(Reader *input);
};

#endif // UUID_H