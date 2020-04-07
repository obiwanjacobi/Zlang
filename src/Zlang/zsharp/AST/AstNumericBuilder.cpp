#include "AstNumericBuilder.h"
#include "../../Utils.h"

uint64_t parseNumber(int offset, int radix, const std::string& text) {
    auto val = text.substr(offset);
    ReplaceAll(val, "_", "");   // remove numerical separators
    return strtoul(val.c_str(), nullptr, radix);
}

antlrcpp::Any AstNumericBuilder::aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) {
    if (nextResult.isNull()) {
        return aggregate;
    }
    return nextResult;
}

antlrcpp::Any AstNumericBuilder::visitNumber(zsharp_parserParser::NumberContext* ctx) {
    auto numeric = std::make_shared<AstNumeric>(ctx);
    numeric->setParent(_parent.get());

    auto val = visitChildren(ctx);
    numeric->setValue(val.as<uint64_t>());
    return numeric;
}

antlrcpp::Any AstNumericBuilder::visitNumber_bin(zsharp_parserParser::Number_binContext* ctx) {
    auto txt = ctx->NUMBERbin()->getText();
    return parseNumber(2, 2, txt);
}

antlrcpp::Any AstNumericBuilder::visitNumber_oct(zsharp_parserParser::Number_octContext* ctx) {
    auto txt = ctx->NUMBERoct()->getText();
    return parseNumber(2, 8, txt);
}

antlrcpp::Any AstNumericBuilder::visitNumber_dec(zsharp_parserParser::Number_decContext* ctx) {
    auto dec = ctx->NUMBERdec();
    if (dec != nullptr) {
        auto txt = dec->getText();
        return parseNumber(0, 10, txt);
    }
    auto dec_pre = ctx->NUMBERdec_prefix();
    if (dec_pre != nullptr) {
        auto txt = dec_pre->getText();
        return parseNumber(2, 10, txt);
    }
    return nullptr;
}

antlrcpp::Any AstNumericBuilder::visitNumber_hex(zsharp_parserParser::Number_hexContext* ctx) {
    auto txt = ctx->NUMBERhex()->getText();
    return parseNumber(2, 16, txt);
}

antlrcpp::Any AstNumericBuilder::visitNumber_char(zsharp_parserParser::Number_charContext* ctx) {
    auto txt = ctx->character()->CHARACTER()->getText();
    return (uint64_t)txt[0];
}
