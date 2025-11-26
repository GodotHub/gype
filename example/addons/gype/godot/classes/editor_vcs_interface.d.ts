
import type { GodotObject } from '@godot/classes/godot_object';


export declare class EditorVCSInterface extends GodotObject {


    public _initialize(projectPath: GDString | StringName | string): boolean;
    public _set_credentials(username: GDString | StringName | string, password: GDString | StringName | string, sshPublicKeyPath: GDString | StringName | string, sshPrivateKeyPath: GDString | StringName | string, sshPassphrase: GDString | StringName | string): void;
    public _get_modified_files_data(): Array<any>;
    public _stage_file(filePath: GDString | StringName | string): void;
    public _unstage_file(filePath: GDString | StringName | string): void;
    public _discard_file(filePath: GDString | StringName | string): void;
    public _commit(msg: GDString | StringName | string): void;
    public _get_diff(identifier: GDString | StringName | string, area: number): Array<any>;
    public _shut_down(): boolean;
    public _get_vcs_name(): GDString;
    public _get_previous_commits(maxCommits: number): Array<any>;
    public _get_branch_list(): Array<any>;
    public _get_remotes(): Array<any>;
    public _create_branch(branchName: GDString | StringName | string): void;
    public _remove_branch(branchName: GDString | StringName | string): void;
    public _create_remote(remoteName: GDString | StringName | string, remoteUrl: GDString | StringName | string): void;
    public _remove_remote(remoteName: GDString | StringName | string): void;
    public _get_current_branch_name(): GDString;
    public _checkout_branch(branchName: GDString | StringName | string): boolean;
    public _pull(remote: GDString | StringName | string): void;
    public _push(remote: GDString | StringName | string, force: boolean): void;
    public _fetch(remote: GDString | StringName | string): void;
    public _get_line_diff(filePath: GDString | StringName | string, text: GDString | StringName | string): Array<any>;
    public create_diff_line(newLineNo: number, oldLineNo: number, content: GDString | StringName | string, status: GDString | StringName | string): Dictionary;
    public create_diff_hunk(oldStart: number, newStart: number, oldLines: number, newLines: number): Dictionary;
    public create_diff_file(newFile: GDString | StringName | string, oldFile: GDString | StringName | string): Dictionary;
    public create_commit(msg: GDString | StringName | string, author: GDString | StringName | string, id: GDString | StringName | string, unixTimestamp: number, offsetMinutes: number): Dictionary;
    public create_status_file(filePath: GDString | StringName | string, changeType: number, area: number): Dictionary;
    public add_diff_hunks_into_diff_file(diffFile: Dictionary, diffHunks: Array<any>): Dictionary;
    public add_line_diffs_into_diff_hunk(diffHunk: Dictionary, lineDiffs: Array<any>): Dictionary;
    public popup_error(msg: GDString | StringName | string): void;


    public static readonly ChangeType: {
        CHANGE_TYPE_NEW: 0;
        CHANGE_TYPE_MODIFIED: 1;
        CHANGE_TYPE_RENAMED: 2;
        CHANGE_TYPE_DELETED: 3;
        CHANGE_TYPE_TYPECHANGE: 4;
        CHANGE_TYPE_UNMERGED: 5;
    };
    public static readonly TreeArea: {
        TREE_AREA_COMMIT: 0;
        TREE_AREA_STAGED: 1;
        TREE_AREA_UNSTAGED: 2;
    };
}

