
import type { Callable } from '@godot/builtins/callable';
import type { OpenXRExtensionWrapper } from '@godot/classes/open_xr_extension_wrapper';
import type { OpenXRFutureResult } from '@godot/classes/open_xr_future_result';


export declare class OpenXRFutureExtension extends OpenXRExtensionWrapper {


    public is_active(): boolean;
    public register_future(future: number, onSuccess: Callable | Function = Callable()): OpenXRFutureResult;
    public cancel_future(future: number): void;


}

