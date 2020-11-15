#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"


void common_hal_add_construct(abstract_module_t *self);
void common_hal_add_deinit(abstract_module_t *self);
float common_hal_add_sum(abstract_module_t *self, float a , float b);
float common_hal_add_ten(abstract_module_t *self);

m_generic_make(add) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_add_construct(self);
    return self;
}



float add_sum(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t * self = (abstract_module_t *)(pos_args[0]);
    float a = mp_obj_get_float(pos_args[1]);
    float b = mp_obj_get_float(pos_args[2]);
    float r = common_hal_add_sum(self, a, b);
    
    return r;
}
 
MP_DEFINE_CONST_FUN_OBJ_KW(add_sum_obj, 2, add_sum);


float add_ten(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t * self = (abstract_module_t *)(pos_args[0]);
    float r = common_hal_add_ten(self);  
    return r;
}

MP_DEFINE_CONST_FUN_OBJ_KW(add_ten_obj, 0, add_ten);


const mp_rom_map_elem_t add_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&add_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&add_obj___exit___obj) },
     {MP_ROM_QSTR(MP_QSTR_sum), MP_ROM_PTR(&add_sum_obj)},
     {MP_ROM_QSTR(MP_QSTR_ten), MP_ROM_PTR(&add_ten_obj)}
};
 
MP_DEFINE_CONST_DICT(add_locals_dict, add_locals_dict_table);

const mp_obj_type_t add_type = {
    {&mp_type_type},
    .name = MP_QSTR__add,
    .make_new = add_make_new,
    .locals_dict = (mp_obj_t)&add_locals_dict,
};



